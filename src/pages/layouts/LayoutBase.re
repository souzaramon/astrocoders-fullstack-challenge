open Types;

module Styles = {
  open Css;

  let container = (~acOverrides) =>
    merge([
      style([
        unsafe("backgroundPosition", "center"),
        width(pct(100.0)),
        height(pct(100.0)),
        display(flexBox),
        flexDirection(column),
        overflowX(hidden),
        backgroundRepeat(noRepeat),
        backgroundSize(cover),
      ]),
      style(acOverrides),
    ]);

  let content =
    style([width(pct(100.0)), height(pct(100.0)), display(flexBox)]);

  let slot =
    style([width(pct(100.0)), height(pct(100.0)), display(flexBox)]);
};

[@react.component]
let make = (~children, ~theme) => {
  <div className={Styles.container(~acOverrides=[theme.background])}>
    <ACHeader dark={theme.dark} />
    <div className=Styles.content>
      <ACSidebar dark={theme.dark} />
      <div className=Styles.slot> children </div>
    </div>
  </div>;
};