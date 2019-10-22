module Styles = {
  open Css;

  let container =
    style([
      width(pct(100.0)),
      paddingRight(px(5)),
      height(pct(100.0)),
      overflowY(auto),
      selector("::-webkit-scrollbar", [width(px(12)), height(px(12))]),
      selector(
        "::-webkit-scrollbar-track",
        [
          hover([
            backgroundColor(rgba(255, 255, 255, 0.1)),
            border(px(1), solid, rgba(255, 255, 255, 0.4)),
          ]),
        ],
      ),
      selector(
        "::-webkit-scrollbar-corner",
        [backgroundColor(transparent)],
      ),
      selector(
        "::-webkit-scrollbar-thumb",
        [
          backgroundColor(rgba(255, 255, 255, 0.4)),
          hover([backgroundColor(rgba(255, 255, 255, 0.7))]),
        ],
      ),
    ]);

  let content = (~acOverrides) => style(acOverrides);
};

// Todo: resizable
[@react.component]
let make = (~children, ~resizable=false, ~overrides=[]) =>
  <div className=Styles.container>
    <div className={Styles.content(~acOverrides=overrides)}> children </div>
  </div>;