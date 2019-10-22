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
    <i className={"material-icons " ++ Styles.label}>
      {switch (value) {
       | Checked => React.string("star")
       | UnChecked => React.string("star_border")
       }}
    </i>
  </ACBtn>;
};