module Styles = {
  open Css;

  let container =
    style([
      display(flexBox),
      flexDirection(column),
      backgroundColor(white),
    ]);

  let item =
    style([
      unsafe("cursor", "pointer"),
      display(flexBox),
      alignItems(center),
      justifyContent(center),
      width(pct(100.0)),
      height(px(40)),
      paddingLeft(px(10)),
      paddingRight(px(10)),
      borderBottom(px(1), solid, hex("f5f5f5")),
      flexWrap(wrap),
      media(
        "(max-width: 1037px)",
        [height(auto), flexDirection(column), alignItems(flexStart)],
      ),
      hover([
        unsafe(
          "boxShadow",
          "inset 1px 0 0 #dadce0, inset -1px 0 0 #dadce0, 0 1px 2px 0 rgba(60,64,67,.3), 0 1px 3px 1px rgba(60,64,67,.15)",
        ),
      ]),
    ]);

  let name =
    style([
      width(px(168)),
      paddingLeft(px(10)),
      fontSize(px(14)),
      fontWeight(bold),
    ]);

  let piece1 = style([display(flexBox), alignItems(center)]);

  let piece2 =
    style([
      unsafe("cursor", "pointer"),
      unsafe("flex", "1"),
      whiteSpace(nowrap),
      overflow(hidden),
      textOverflow(ellipsis),
      display(block),
      minWidth(px(0)),
      color(hex("5f6368")),
      fontWeight(normal),
      media("(max-width: 1037px)", [whiteSpace(normal), padding(px(10))]),
      media("(min-width: 1037px)", [width(px(400))]),
    ]);

  let piece3 =
    style([
      unsafe("flex", "1"),
      fontWeight(bold),
      fontSize(rem(0.75)),
      display(flexBox),
      justifyContent(flexEnd),
      media("(max-width: 1037px)", [display(none)]),
    ]);

  let noResult =
    style([
      width(pct(100.0)),
      height(px(100)),
      display(flexBox),
      justifyContent(center),
      alignItems(center),
      backgroundColor(hex("f5f5f5")),
    ]);
};

module TweetsQueryConfig = [%graphql
  {|
  query {
    tweets {
      id
      text
      user {
        screen_name
      }
      created_at
    }
  }
|}
];

module TweetsQuery = ReasonApolloHooks.Query.Make(TweetsQueryConfig);

[@react.component]
let make = () => {
  let (_simple, full) = TweetsQuery.use();
  let (filter, _dispatch) = React.useContext(ContextFilter.context);

  <ul className=Styles.container>
    {switch (full) {
     | {loading: true, data: None} => <p> {React.string("Loading...")} </p>
     | {data: Some(data)} =>
       let filterredLi =
         data##tweets
         ->Belt.Array.keepMap(tweet =>
             if (filter === ""
                 || Js.String.includes(
                      String.uppercase(filter),
                      String.uppercase(tweet##user##screen_name),
                    )
                 || Js.String.includes(
                      String.uppercase(filter),
                      String.uppercase(tweet##text),
                    )) {
               Some(
                 <li
                   key={tweet##id}
                   className=Styles.item
                   onClick={_ =>
                     ReasonReactRouter.push("/mail/" ++ tweet##id)
                   }>
                   <div className=Styles.piece1>
                     <ACCheckBox
                       value=ACCheckBox.UnChecked
                       color={Css.rgba(0, 0, 0, 0.2)}
                     />
                     <ACCheckBoxFav
                       value=ACCheckBoxFav.UnChecked
                       color={Css.rgba(0, 0, 0, 0.2)}
                     />
                     <div className=Styles.name>
                       <span> {React.string(tweet##user##screen_name)} </span>
                     </div>
                   </div>
                   <div className=Styles.piece2>
                     {React.string(tweet##text)}
                   </div>
                   <div className=Styles.piece3>
                     <span>
                       {React.string(
                          Utils.fromISOStringToLocale(tweet##created_at),
                        )}
                     </span>
                   </div>
                 </li>,
               );
             } else {
               None;
             }
           );

       Belt.Array.length(filterredLi) > 0
         ? filterredLi->React.array
         : <div className=Styles.noResult>
             {React.string("No results to show :(")}
           </div>;

     | _ => <div />
     }}
  </ul>;
};
