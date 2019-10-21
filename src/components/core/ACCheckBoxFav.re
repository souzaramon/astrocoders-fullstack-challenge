type validValues =
  | Checked
  | UnChecked;

[@react.component]
let make = (~value, ~onClick=_ => (), ~color=Css.hex("000")) => {
  let acColor =
    switch (value) {
    | Checked => Css.hex("f4c352")
    | UnChecked => color
    };

  <ACBtn color=acColor onClick>
    <i className="material-icons">
      {switch (value) {
       | Checked => React.string("star")
       | UnChecked => React.string("star_border")
       }}
    </i>
  </ACBtn>;
};