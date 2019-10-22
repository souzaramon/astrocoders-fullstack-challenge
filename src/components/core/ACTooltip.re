type positions =
  | Bottom
  | Top;

module Styles = {
  open Css;

  let container = (~acPosition, ~acPointer, ~acDisabled) => {
    let horizontalCenter = [left(pct(-25.0))];
    let baseOffset = px(-30);

    let computedAcPositon =
      switch (acPosition) {
      | Top => [top(baseOffset), ...horizontalCenter]
      | Bottom => [bottom(baseOffset), ...horizontalCenter]
      };

    style([
      unsafe("cursor", acPointer),
      display(inlineBlock),
      position(relative),
      zIndex(10),
      hover([
        selector(
          ".ACTooltip-text",
          !acDisabled
            ? [
              visibility(visible),
              opacity(1.0),
              transform(scale(1.0, 1.0)),
            ]
            : [],
        ),
      ]),
      selector(
        ".ACTooltip-text",
        [
          display(flexBox),
          justifyContent(center),
          alignItems(center),
          width(pct(150.0)),
          position(absolute),
          visibility(hidden),
          opacity(0.0),
          transform(scale(0.0, 0.0)),
          transitionProperty("transform, opacity, visibility"),
          transitionDuration(250),
          transitionTimingFunction(cubicBesier(0.4, 0.0, 0.2, 1.0)),
          selector(
            "span",
            [
              background(rgba(0, 0, 0, 0.7)),
              padding(px(4)),
              borderRadius(px(3)),
              fontSize(rem(0.8)),
              color(white),
              whiteSpace(nowrap),
            ],
          ),
          ...computedAcPositon,
        ],
      ),
    ]);
  };
};

[@react.component]
let make =
    (~children, ~position=Bottom, ~text, ~pointer="auto", ~disabled=false) => {
  <div
    className={Styles.container(
      ~acPosition=position,
      ~acPointer=pointer,
      ~acDisabled=disabled,
    )}>
    <div className="ACTooltip-text">
      <span> {React.string(text)} </span>
    </div>
    children
  </div>;
};