[@bs.send]
external getBoundingClientRect: Dom.element => Dom.domRect =
  "getBoundingClientRect";

module Styles = {
  open Css;

  let container = (~acOverrides) =>
    merge([
      style([
        unsafe(
          "boxShadow",
          "0 8px 10px 1px rgba(0,0,0,0.14), 0 3px 14px 2px rgba(0,0,0,0.12), 0 5px 5px -3px rgba(0,0,0,0.2)",
        ),
        fontSize(rem(0.875)),
        lineHeight(px(20)),
        paddingTop(px(6)),
        paddingBottom(px(6)),
        backgroundColor(hex("fff")),
        position(absolute),
        left(px(25)),
        top(px(25)),
        transitionDuration(218),
        transitionProperty("opacity"),
        transitionTimingFunction(ease),
        zIndex(7),
        borderRadius(px(4)),
        userSelect(none),
      ]),
      style(acOverrides),
    ]);
};

[@react.component]
let make = (~children, ~anchorRef) => {
  let (overrides, setOverrides) = React.useState(() => []);

  React.useEffect2(
    () =>
      None,
          // anchorRef->React.Ref.current -> getBoundingClientRect;
    (anchorRef, setOverrides),
  );

  <div className={Styles.container(~acOverrides=overrides)}> children </div>;
};