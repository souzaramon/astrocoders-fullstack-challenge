type validValues =
  | Checked
  | Partially
  | UnChecked;

[@react.component]
let make = (~value, ~onClick=_ => (), ~color=Css.hex("000"), ~overrides=[]) => {
  <ACBtn color onClick overrides>
    <ACIcon
      name={
        switch (value) {
        | Checked => "check_box"
        | Partially => "indeterminate_check_box"
        | UnChecked => "check_box_outline_blank"
        }
      }
    />
  </ACBtn>;
};