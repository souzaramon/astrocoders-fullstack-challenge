module Styles = {
  open Css;

  let container =
    style([
      unsafe("flex", "1"),
      height(px(46)),
      width(pct(100.0)),
      maxWidth(px(734)),
      marginLeft(px(10)),
      marginRight(auto),
      display(flexBox),
      alignItems(center),
      borderRadius(px(8)),
      backgroundColor(rgba(241, 243, 244, 0.24)),
      transitionProperty("background"),
      transitionDuration(150),
      transitionTimingFunction(cubicBesier(0.4, 0.0, 0.2, 1.0)),
      focusWithin([
        backgroundColor(white),
        selector("button", [color(hex("5f6368"))]),
        selector("input", [placeholder([color(hex("abb2b6"))])]),
      ]),
    ]);

  let input =
    style([
      unsafe("all", "unset"),
      placeholder([color(white)]),
      width(pct(100.0)),
      color(rgba(255, 255, 255, 0.87)),
      fontSize(px(16)),
      focus([color(black)]),
    ]);
};

[@react.component]
let make = (~placeholder="Search mail") => {
  let (searchTerm, setSearchTerm) = React.useState(() => "");

  <div className=Styles.container>
    <ACBtn
      disabled=true
      overrides=[Css.marginLeft(Css.px(10)), Css.marginRight(Css.px(10))]>
      <i className="material-icons"> {React.string("search")} </i>
    </ACBtn>
    <input
      className=Styles.input
      value=searchTerm
      onChange={e => setSearchTerm(ReactEvent.Form.target(e)##value)}
      placeholder
    />
    <ACTooltip text="Clear search" disabled={searchTerm === ""}>
      <ACBtn onClick={_ => setSearchTerm(_ => "")} hidden={searchTerm === ""}>
        <i className="material-icons"> {React.string("close")} </i>
      </ACBtn>
    </ACTooltip>
    <ACBtn overrides=[Css.marginRight(Css.px(10))] disabled=true>
      <i className="material-icons"> {React.string("arrow_drop_down")} </i>
    </ACBtn>
  </div>;
};