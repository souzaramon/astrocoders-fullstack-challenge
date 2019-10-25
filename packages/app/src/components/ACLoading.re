module Styles = {
  open Css;

  let container =
    style([
      width(pct(100.0)),
      height(pct(100.0)),
      display(flexBox),
      justifyContent(center),
      alignItems(center),
      selector("span", [fontSize(px(20)), color(hex("757575"))]),
    ]);
};

[@react.component]
let make = () =>
  <div className=Styles.container>
    <span> {React.string("Loading GMail")} </span>
  </div>;
