module Styles = {
  open Css;

  let container =
    style([
      width(pct(100.0)),
      height(pct(100.0)),
      display(flexBox),
      justifyContent(center),
      alignItems(center),
      flexDirection(column),
      selector("span", [fontSize(px(20)), color(hex("757575"))]),
    ]);

  let bestLogo = style([opacity(0.4), margin(px(25)), width(px(120))]);
};

[@react.component]
let make = () =>
  <div className=Styles.container>
    <img
      className=Styles.bestLogo
      src="https://d33wubrfki0l68.cloudfront.net/b8f71088a0c9bc92d67476a361f35690d157d0e5/517c2/static/logo-c5d890fb431b53a7c61800feccd65ac2.png"
    />
    <span> {React.string("Loading GMail")} </span>
  </div>;
