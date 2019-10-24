type validValues =
  | Checked
  | UnChecked;

module Styles = {
  open Css;

  let label = (~acColor) => style([fontSize(rem(1.2)), color(acColor)]);
};

[@react.component]
let make = (~value, ~onClick=_ => (), ~color=Css.hex("000")) => {
  // I'll implement this just because is the easest way of show this working on screen wihout thinking
  // about implementation, but that is not right
  let (iValue, setIValue) = React.useState(() => value);

  let acColor =
    switch (iValue) {
    | Checked => Css.hex("f4c352")
    | UnChecked => color
    };

  <ACTooltip
    label={
      switch (iValue) {
      | UnChecked => "Not starred"
      | Checked => "Starred"
      }
    }>
    <ACBtn
      color=acColor
      onClick={_ =>
        switch (iValue) {
        | UnChecked => setIValue(_ => Checked)
        | Checked => setIValue(_ => UnChecked)
        }
      }>
      <ACIcon
        className={Styles.label(~acColor)}
        name={
          switch (iValue) {
          | Checked => "star"
          | UnChecked => "star_border"
          }
        }
      />
    </ACBtn>
  </ACTooltip>;
};
