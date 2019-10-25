module Styles = {
  open Css;

  let container = (~acSelected) =>
    style([
      unsafe("cursor", "pointer"),
      backgroundColor(acSelected ? hex("174ea6") : transparent),
      display(flexBox),
      alignItems(center),
      justifyContent(center),
      width(pct(100.0)),
      height(px(40)),
      paddingLeft(px(10)),
      paddingRight(px(10)),
      borderBottom(
        px(1),
        solid,
        acSelected ? hex("174ea6") : hex("f5f5f5"),
      ),
      flexWrap(wrap),
      media(
        "(max-width: 1037px)",
        [height(auto), flexDirection(column), alignItems(flexStart)],
      ),
      hover([
        acSelected
          ? unsafe("boxShadow", "none")
          : unsafe(
              "boxShadow",
              "inset 1px 0 0 #dadce0, inset -1px 0 0 #dadce0, 0 1px 2px 0 rgba(60,64,67,.3), 0 1px 3px 1px rgba(60,64,67,.15)",
            ),
      ]),
    ]);

  let column1 = (~acSelected) =>
    style([
      display(flexBox),
      alignItems(center),
      color(acSelected ? white : hex("000")),
    ]);

  let column2 = (~acSelected) =>
    style([
      width(px(168)),
      paddingLeft(px(10)),
      fontSize(px(14)),
      fontWeight(bold),
      color(acSelected ? hex("fff") : hex("000")),
    ]);

  let column3 = (~acSelected) =>
    style([
      unsafe("cursor", "pointer"),
      unsafe("flex", "1"),
      whiteSpace(nowrap),
      overflow(hidden),
      textOverflow(ellipsis),
      display(block),
      minWidth(px(0)),
      color(acSelected ? white : hex("5f6368")),
      fontWeight(normal),
      media("(max-width: 1037px)", [whiteSpace(normal), padding(px(10))]),
      media("(min-width: 1037px)", [width(px(400))]),
    ]);

  let column4 = (~acSelected) =>
    style([
      unsafe("flex", "1"),
      fontWeight(bold),
      fontSize(rem(0.75)),
      display(flexBox),
      color(acSelected ? white : hex("000")),
      justifyContent(flexEnd),
      media("(max-width: 1037px)", [display(none)]),
    ]);
};

[@react.component]
let make = (~tweetId, ~screenName, ~text, ~createdAt) => {
  let (selected, setSelected) = React.useState(() => false);

  <li
    className={Styles.container(~acSelected=selected)}
    onClick={_ => ReasonReactRouter.push("/mail/" ++ tweetId)}>
    <div className={Styles.column1(~acSelected=selected)}>
      <ACCheckBox
        onClick={_ => setSelected(_ => !selected)}
        value={selected ? ACCheckBox.Checked : ACCheckBox.UnChecked}
        color={selected ? Css.white : Css.rgba(0, 0, 0, 0.2)}
      />
      <ACCheckBoxFav
        value=ACCheckBoxFav.UnChecked
        color={selected ? Css.white : Css.rgba(0, 0, 0, 0.2)}
      />
      <div className={Styles.column2(~acSelected=selected)}>
        <span> {React.string(screenName)} </span>
      </div>
    </div>
    <div className={Styles.column3(~acSelected=selected)}>
      {React.string(text)}
    </div>
    <div className={Styles.column4(~acSelected=selected)}>
      <span> {React.string(Utils.fromISOStringToLocale(createdAt))} </span>
    </div>
  </li>;
};
