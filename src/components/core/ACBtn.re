module Styles = {
  open Css;

  let container =
      (~acSize, ~acColor, ~acRounded, ~acHidden, ~acDisabled, ~acOverrides) =>
    merge([
      style([
        unsafe("all", "unset"),
        visibility(acHidden ? hidden : visible),
        opacity(acDisabled ? 0.4 : 1.0),
        unsafe("cursor", acDisabled ? "normal" : "pointer"),
        overflow(hidden),
        position(relative),
        display(flexBox),
        justifyContent(center),
        alignItems(center),
        width(px(acSize)),
        height(px(acSize)),
        hover([before([transform(scale(0.6, 0.6)), opacity(0.122)])]),
        borderRadius(acRounded ? pct(50.0) : zero),
        color(acColor),
        before(
          !acDisabled
            ? [
              unsafe("content", ""),
              display(block),
              position(absolute),
              top(px(-15)),
              left(px(-15)),
              bottom(px(-15)),
              right(px(-15)),
              opacity(0.0),
              transform(scale(0.0, 0.0)),
              borderRadius(acRounded ? pct(50.0) : zero),
              background(currentColor),
              transitionProperty("transform, opacity, visibility"),
              transitionDuration(250),
              transitionTimingFunction(cubicBesier(0.4, 0.0, 0.2, 1.0)),
            ]
            : [],
        ),
      ]),
      acOverrides,
    ]);
};

[@react.component]
let make =
    (
      ~children,
      ~size=36,
      ~color=Css.hex("fff"),
      ~rounded=true,
      ~hidden=false,
      ~disabled=false,
      ~overrides=[],
    ) => {
  <button
    className={Styles.container(
      ~acSize=size,
      ~acColor=color,
      ~acRounded=rounded,
      ~acHidden=hidden,
      ~acDisabled=disabled,
      ~acOverrides=Css.style(overrides),
    )}
    disabled>
    children
  </button>;
};