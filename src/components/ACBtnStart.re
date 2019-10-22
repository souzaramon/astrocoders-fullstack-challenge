module Styles = {
  open Css;

  let container = (~acOverrides) =>
    merge([
      style([
        unsafe("all", "unset"),
        unsafe("cursor", "pointer"),
        unsafe(
          "boxShadow",
          "0 1px 2px 0 rgba(60,64,67,0.302), 0 1px 3px 1px rgba(60,64,67,0.149)",
        ),
        unsafe("letterSpacing", "0.25px"),
        display(inlineFlex),
        alignItems(center),
        color(hex("3c4043")),
        paddingRight(px(24)),
        borderRadius(px(24)),
        fontSize(rem(0.875)),
        backgroundColor(hex("fff")),
        fontFamily("Google Sans"),
        fontWeight(bolder),
        before([
          unsafe("content", ""),
          unsafe("backgroundPosition", "center"),
          unsafe("backgroundSize", "32px"),
          display(block),
          backgroundImage(
            url(
              "https://www.gstatic.com/images/icons/material/colored_icons/1x/create_32dp.png",
            ),
          ),
          backgroundRepeat(noRepeat),
          height(px(48)),
          minWidth(px(56)),
        ]),
        hover([backgroundColor(hex("fafafb"))]),
      ]),
      style(acOverrides),
    ]);
};

[@react.component]
let make = (~label="Compose", ~overrides=[]) =>
  <button className={Styles.container(~acOverrides=overrides)}>
    {React.string(label)}
  </button>;