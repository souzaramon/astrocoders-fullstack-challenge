module Styles = {
  open Css;

  let container = (~acDark) =>
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
      backgroundColor(acDark ? rgba(241, 243, 244, 0.24) : hex("f1f3f4")),
      transitionProperty("background"),
      transitionDuration(150),
      transitionTimingFunction(cubicBesier(0.4, 0.0, 0.2, 1.0)),
      focusWithin([
        unsafe(
          "boxShadow",
          "0 1px 1px 0 rgba(65,69,73,0.3), 0 1px 3px 1px rgba(65,69,73,0.15)",
        ),
        backgroundColor(white),
        selector("button", [color(hex("5f6368"))]),
        selector("input", [placeholder([color(hex("abb2b6"))])]),
      ]),
    ]);

  let input = (~acDark) =>
    style([
      unsafe("all", "unset"),
      placeholder([color(acDark ? white : hex("abb2b6"))]),
      width(pct(100.0)),
      color(acDark ? rgba(255, 255, 255, 0.87) : hex("abb2b6")),
      fontSize(px(16)),
      focus([color(black)]),
    ]);
};

[@react.component]
let make = (~placeholder="Search mail", ~dark=true) => {
  let (searchTerm, setSearchTerm) = React.useState(() => "");

  <div className={Styles.container(~acDark=dark)}>
    <ACBtn
      color={dark ? Css.hex("fff") : Css.hex("202124")}
      disabled=true
      overrides=[Css.marginLeft(Css.px(10)), Css.marginRight(Css.px(10))]>
      <ACIcon name="search" />
    </ACBtn>
    <input
      className={Styles.input(~acDark=dark)}
      value=searchTerm
      onChange={e => setSearchTerm(ReactEvent.Form.target(e)##value)}
      placeholder
    />
    <ACTooltip label="Clear search" disabled={searchTerm === ""}>
      <ACBtn
        color={dark ? Css.hex("fff") : Css.hex("202124")}
        onClick={_ => setSearchTerm(_ => "")}
        hidden={searchTerm === ""}>
        <ACIcon name="close" />
      </ACBtn>
    </ACTooltip>
    <ACBtn
      color={dark ? Css.hex("fff") : Css.hex("202124")}
      overrides=[Css.marginRight(Css.px(10))]
      disabled=true>
      <ACIcon name="arrow_drop_down" />
    </ACBtn>
  </div>;
};