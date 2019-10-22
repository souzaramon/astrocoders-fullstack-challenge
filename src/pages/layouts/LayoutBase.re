module Styles = {
  open Css;

  let container =
    style([
      width(pct(100.0)),
      height(pct(100.0)),
      display(flexBox),
      flexDirection(column),
    ]);

  let content =
    style([width(pct(100.0)), height(pct(100.0)), display(flexBox)]);

  let slot =
    style([width(pct(100.0)), height(pct(100.0)), display(flexBox)]);
};

[@react.component]
let make = (~children) =>
  <div className=Styles.container>
    <ACHeader />
    <div className=Styles.content>
      <ACSidebar />
      <div className=Styles.slot> children </div>
    </div>
  </div>;