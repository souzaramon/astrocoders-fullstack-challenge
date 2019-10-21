type value =
  | Checked
  | Partially
  | UnChecked;

[@react.component]
let make = (~value, ~onClick, ~color=Css.hex("000")) => {
  <ACBtn color onClick>
    <i className="material-icons">
      {switch (value) {
       | Checked => React.string("check_box")
       | Partially => React.string("indeterminate_check_box")
       | UnChecked => React.string("check_box_outline_blank")
       }}
    </i>
  </ACBtn>;
};