module Styles = {
  open Css;

  let container = style([width(px(256))]);

  let list =
    style([display(flexBox), alignItems(center), flexDirection(column)]);

  let item =
    style([
      unsafe("cursor", "pointer"),
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
      // backgroundColor(rgba(241, 243, 244, 0.24)),
      color(hex("fff")),
      unsafe("textShadow", "0 1px 2px rgba(0,0,0,.65)"),
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
    <ul className=Styles.list>
      <li className=Styles.item>
        <i className="material-icons"> {React.string("inbox")} </i>
        <span> {React.string("Inbox")} </span>
      </li>
      <li className=Styles.item>
        <i className="material-icons"> {React.string("star")} </i>
        <span> {React.string("Starred")} </span>
      </li>
      <li className=Styles.item>
        <i className="material-icons"> {React.string("access_time")} </i>
        <span> {React.string("Snoozed")} </span>
      </li>
      <li className=Styles.item>
        <i className="material-icons"> {React.string("label_important")} </i>
        <span> {React.string("Important")} </span>
      </li>
      <li className=Styles.item>
        <i className="material-icons"> {React.string("send")} </i>
        <span> {React.string("Sent")} </span>
      </li>
      <li className=Styles.item>
        <i className="material-icons">
          {React.string("insert_drive_file")}
        </i>
        <span> {React.string("Draft")} </span>
      </li>
      <li className=Styles.item>
        <i className="material-icons"> {React.string("label")} </i>
        <span> {React.string("Categories")} </span>
      </li>
    </ul>
  </div>;