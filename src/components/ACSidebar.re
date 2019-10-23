module Styles = {
  open Css;

  let container = (~acDense) =>
    style(!acDense ? [minWidth(px(256))] : [maxWidth(px(72))]);

  let links = (~acDark, ~acDense) =>
    style([
      unsafe("listStyle", "none"),
      display(flexBox),
      alignItems(center),
      flexDirection(column),
      paddingRight(px(15)),
      paddingLeft(!acDense ? px(0) : px(15)),
      marginRight(!acDense ? px(0) : px(10)),
      marginLeft(!acDense ? px(0) : px(10)),
      selector(
        ".active",
        [
          backgroundColor(
            acDark ? rgba(241, 243, 244, 0.24) : rgba(0, 0, 0, 0.10),
          ),
        ],
      ),
      selector(".material-icons", [fontSize(rem(1.2))]),
    ]);

  let link = (~acDark, ~acDense) =>
    style([
      unsafe("cursor", "pointer"),
      unsafe("textShadow", acDark ? "0 1px 2px rgba(0,0,0,.65)" : "none"),
      unsafe("borderRadius", !acDense ? "0 16px 16px 0" : "50%"),
      unsafe("padding", !acDense ? "0 12px 0 26px" : "7px"),
      width(!acDense ? pct(100.0) : px(32)),
      height(px(32)),
      marginTop(!acDense ? px(0) : px(5)),
      whiteSpace(nowrap),
      hover([
        backgroundColor(
          acDark ? rgba(241, 243, 244, 0.15) : rgba(0, 0, 0, 0.05),
        ),
      ]),
      display(flexBox),
      alignItems(center),
      color(acDark ? Css.hex("fff") : Css.hex("767676")),
      fontSize(rem(0.875)),
      fontWeight(bold),
      textTransform(capitalize),
      selector(
        "span",
        !acDense
          ? [marginLeft(px(18)), marginRight(px(49))] : [display(none)],
      ),
    ]);
};

[@react.component]
let make = (~dense=false, ~dark=true) => {
  <div className={Styles.container(~acDense=dense)}>
    <ACBtnStart
      dense
      overrides=[
        Css.marginBottom(Css.px(16)),
        Css.marginTop(Css.px(16)),
        Css.marginLeft(Css.px(10)),
      ]
    />
    <ul className={Styles.links(~acDark=dark, ~acDense=dense)}>
      {Belt.Array.map(
         [|
           ("Inbox", "inbox", "active"),
           ("Starred", "star", ""),
           ("Snoozed", "access_time", ""),
           ("Important", "label_important", ""),
           ("Sent", "send", ""),
           ("Draft", "insert_drive_file", ""),
           ("Categories", "label", ""),
         |],
         ((label, icon, override)) =>
         <li
           key=label
           className={
             Styles.link(~acDark=dark, ~acDense=dense) ++ " " ++ override
           }>
           <ACIcon name=icon />
           <span> {React.string(label)} </span>
         </li>
       )
       ->ReasonReact.array}
    </ul>
  </div>;
};