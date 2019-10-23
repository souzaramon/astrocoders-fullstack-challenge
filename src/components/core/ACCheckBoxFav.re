type validValues =
  | Checked
  | UnChecked;

module Styles = {
  open Css;

  let label = style([fontSize(rem(1.2))]);
};

[@react.component]
let make = (~value, ~onClick=_ => (), ~color=Css.hex("000")) => {
  let acColor =
    switch (value) {
    | Checked => Css.hex("f4c352")
    | UnChecked => color
    };

  <ACBtn color=acColor onClick>
    <ACIcon
      className=Styles.label
      name={
        switch (value) {
        | Checked => "star"
        | UnChecked => "star_border"
        }
      }
    />
  </ACBtn>;
};