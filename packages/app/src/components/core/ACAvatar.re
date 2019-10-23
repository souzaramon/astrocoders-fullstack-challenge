module Styles = {
  open Css;

  let container = (~acSize, ~acOverrides) =>
    merge([
      style([
        width(px(acSize)),
        height(px(acSize)),
        borderRadius(pct(50.0)),
        objectFit(cover),
      ]),
      style(acOverrides),
    ]);
};

[@react.component]
let make = (~url, ~size=36, ~overrides=[]) =>
  <img
    className={Styles.container(~acSize=size, ~acOverrides=overrides)}
    src=url
    alt="User Avatar"
  />;