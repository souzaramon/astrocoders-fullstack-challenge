module Styles = {
  open Css;

  let container = (~acSize, ~acBackgroundColor, ~acOverrides) =>
    merge([
      style([
        userSelect(none),
        width(px(acSize)),
        height(px(acSize)),
        backgroundColor(acBackgroundColor),
        borderRadius(pct(50.0)),
        color(white),
        display(flexBox),
        justifyContent(center),
        alignItems(center),
        fontSize(rem(0.8)),
        fontWeight(bold),
      ]),
      style(acOverrides),
    ]);
};

[@react.component]
let make =
    (~count, ~size=24, ~backgroundColor=Css.hex("db4437"), ~overrides=[]) => {
  <div
    className={Styles.container(
      ~acSize=size,
      ~acBackgroundColor=backgroundColor,
      ~acOverrides=overrides,
    )}>
    {React.string(string_of_int(count))}
  </div>;
};