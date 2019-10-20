module Styles = {
  open Css;

  let container = (~acPosition) => {
    let horizontalCenter = [left(pct(-25.0))];
    let baseOffset = px(-10);

    let computedAcPositon =
      switch (acPosition) {
      | "top" => [top(baseOffset), ...horizontalCenter]
      | _ => [bottom(baseOffset), ...horizontalCenter]
      };

    style([
      display(inlineBlock),
      position(relative),
      hover([
        selector(
          ".ACTooltip-text",
          [visibility(visible), opacity(1.0), transform(scale(1.0, 1.0))],
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
              background(rgba(0, 0, 0, 0.6)),
              padding(px(1)),
              borderRadius(px(3)),
              fontSize(rem(0.6)),
              color(white),
            ],
          ),
          ...computedAcPositon,
        ],
      ),
    ]);
  };
};

[@react.component]
let make = (~children, ~position="bottom", ~text) => {
  <div className={Styles.container(~acPosition=position)}>
    <div className="ACTooltip-text">
      <span> {React.string(text)} </span>
    </div>
    children
  </div>;
};