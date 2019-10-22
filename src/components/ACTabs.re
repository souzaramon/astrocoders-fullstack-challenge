module Styles = {
  open Css;

  let container =
    style([
      backgroundColor(rgba(255, 255, 255, 0.902)),
      height(px(56)),
      padding(px(3)),
      display(flexBox),
    ]);

  let tab =
    style([
      unsafe("cursor", "pointer"),
      userSelect(none),
      width(px(251)),
      height(pct(100.0)),
      display(flexBox),
      alignItems(center),
      borderBottom(px(3), solid, hex("da4725")),
      color(hex("da4725")),
      hover([backgroundColor(hex("e5e5e9"))]),
      selector("i", [margin(px(16)), fontSize(rem(1.3))]),
      selector("span", [fontSize(rem(0.95)), fontFamily("Google Sans")]),
    ]);
};

[@react.component]
let make = () =>
  <header className=Styles.container>
    <div className=Styles.tab>
      <i className="material-icons"> {React.string("chat")} </i>
      <span> {React.string("Primary")} </span>
    </div>
  </header>;