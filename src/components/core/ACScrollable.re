module Styles = {
  open Css;

  let container = (~acHeight) =>
    style([
      height(acHeight),
      width(pct(100.0)),
      backgroundColor(gray),
      overflowY(auto),
      selector("::-webkit-scrollbar", [width(px(16)), height(px(16))]),
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
};

// Todo: resizable
[@react.component]
let make = (~children, ~height, ~resizable=false) =>
  <div className={Styles.container(~acHeight=height)}> children </div>;