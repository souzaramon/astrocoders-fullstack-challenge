module Styles = {
  open Css;

  let container =
    style([
      display(flexBox),
      flexDirection(column),
      backgroundColor(white),
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

[@react.component]
let make = (~data) => {
  let (filter, _dispatch) = React.useContext(ContextFilter.context);

  let tweets =
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
          Some(tweet);
        } else {
          None;
        }
      );

  <ul className=Styles.container>
    {Belt.Array.length(tweets) > 0
       ? tweets
         ->Belt.Array.map(tweet =>
             <ACEmailListItem
               key={
                 tweet##id;
               }
               tweetId={
                 tweet##id;
               }
               createdAt={
                 tweet##created_at;
               }
               screenName={
                 tweet##user##screen_name;
               }
               text={
                 tweet##text;
               }
             />
           )
         ->React.array
       : <div className=Styles.noResult>
           {React.string("No results to show :(")}
         </div>}
  </ul>;
};
