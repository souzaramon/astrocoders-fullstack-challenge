module Styles = {
  open Css;

  let container =
    style([
      unsafe("listStyle", "none"),
      unsafe("boxShadow", "inset 0 -1px 0 0 rgba(100,121,143,0.122)"),
      display(flexBox),
      flexDirection(column),
      width(pct(100.0)),
      height(pct(100.0)),
      backgroundColor(rgba(255, 255, 255, 0.902)),
    ]);

  let items =
    style([
      unsafe("cursor", "pointer"),
      unsafe("boxShadow", "inset 0 -1px 0 0 rgba(100,121,143,0.122)"),
      display(flexBox),
      justifyContent(spaceBetween),
      alignItems(center),
      width(pct(100.0)),
      height(px(40)),
      padding(px(10)),
      hover([
        unsafe(
          "boxShadow",
          "inset 1px 0 0 #dadce0, inset -1px 0 0 #dadce0, 0 1px 2px 0 rgba(60,64,67,.3), 0 1px 3px 1px rgba(60,64,67,.15)",
        ),
      ]),
      selector(
        ".subject, .from",
        [
          unsafe("letterSpacing", ".2px"),
          color(hex("202124")),
          paddingLeft(px(10)),
          paddingRight(px(32)),
          fontSize(rem(0.875)),
          fontWeight(bold),
          lineHeight(px(20)),
          userSelect(none),
        ],
      ),
      selector(".subject", [unsafe("flex", "1")]),
    ]);

  let leftActions = style([display(flexBox)]);

  let rightActions = style([display(flexBox)]);
};

[@react.component]
let make = (~emails=[||]) => {
  <ul className=Styles.container>
    {Belt.Array.map(emails, i =>
       <li
         key={string_of_int(i)}
         className=Styles.items
         onClick={_ => ReasonReact.Router.push("/mail/1")}>
         <div className=Styles.leftActions>
           <ACCheckBox value=ACCheckBox.UnChecked />
           <ACTooltip label="Unstarred">
             <ACCheckBoxFav value=ACCheckBoxFav.UnChecked />
           </ACTooltip>
         </div>
         <span className="from"> {React.string("Tester")} </span>
         <span className="subject">
           {React.string("Mensagem de teste")}
         </span>
         <div className=Styles.rightActions> {React.string("18h")} </div>
       </li>
     )
     ->ReasonReact.array}
  </ul>;
};