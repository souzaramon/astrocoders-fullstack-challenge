module Styles = {
  open Css;

  let container = style([minWidth(px(256))]);

  let links =
    style([
      unsafe("listStyle", "none"),
      display(flexBox),
      alignItems(center),
      flexDirection(column),
      paddingRight(px(15)),
      selector(".active", [backgroundColor(rgba(241, 243, 244, 0.24))]),
      selector(".material-icons", [fontSize(rem(1.2))]),
    ]);

  let link =
    style([
      unsafe("cursor", "pointer"),
      unsafe("textShadow", "0 1px 2px rgba(0,0,0,.65)"),
      width(pct(100.0)),
      height(px(32)),
      paddingLeft(px(26)),
      paddingRight(px(12)),
      whiteSpace(nowrap),
      borderTopRightRadius(px(16)),
      borderBottomRightRadius(px(16)),
      hover([backgroundColor(rgba(241, 243, 244, 0.15))]),
      display(flexBox),
      alignItems(center),
      color(hex("fff")),
      fontSize(rem(0.875)),
      fontWeight(bold),
      textTransform(capitalize),
      selector("span", [marginLeft(px(18)), marginRight(px(49))]),
    ]);
};

[@react.component]
let make = (~dense=false) =>
  <div className=Styles.container>
    <ACBtnStart
      overrides=[
        Css.marginBottom(Css.px(16)),
        Css.marginTop(Css.px(16)),
        Css.marginLeft(Css.px(10)),
      ]
    />
    <ul className=Styles.links>
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
         <li key=label className={Styles.link ++ " " ++ override}>
           <i className="material-icons"> {React.string(icon)} </i>
           <span> {React.string(label)} </span>
         </li>
       )
       ->ReasonReact.array}
    </ul>
  </div>;