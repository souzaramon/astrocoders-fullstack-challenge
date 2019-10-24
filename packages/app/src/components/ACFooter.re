module Styles = {
  open Css;

  let container = (~acDark) =>
    style([
      unsafe("cursor", "pointer"),
      width(pct(100.0)),
      height(px(40)),
      marginTop(px(16)),
      marginBottom(px(16)),
      paddingLeft(px(16)),
      paddingRight(px(16)),
      display(flexBox),
      justifyContent(spaceBetween),
      alignItems(center),
      selector(
        "span",
        [
          unsafe("textShadow", acDark ? "rgba(0,0,0,0.8) 0 0 3px" : ""),
          color(acDark ? rgba(255, 255, 255, 0.70) : hex("767676")),
          fontSize(rem(0.75)),
          lineHeight(px(20)),
          hover([textDecoration(underline)]),
        ],
      ),
    ]);
};

[@react.component]
let make = (~dark=true) =>
  <footer className={Styles.container(~acDark=dark)}>
    <span> {React.string({js|0 GB (0%) of 15 GB used|js})} </span>
    <span>
      {React.string({js|Terms · Privacy · Program Policies|js})}
    </span>
    <span> {React.string({js|Last account activity: 1 hour ago|js})} </span>
  </footer>;
