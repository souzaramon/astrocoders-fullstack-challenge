module Styles = {
  open Css;

  let container = (~acDark) =>
    style([
      display(flexBox),
      alignItems(center),
      justifyContent(spaceBetween),
      width(pct(100.0)),
      height(px(64)),
      padding(px(8)),
      borderBottom(
        px(1),
        solid,
        acDark ? rgba(255, 255, 255, 0.1) : rgba(0, 0, 0, 0.1),
      ),
    ]);

  let box = (~acOverrides) =>
    merge([
      style([display(flexBox), alignItems(center)]),
      style(acOverrides),
    ]);

  let logo = style([width(px(109)), height(px(40)), marginTop(px(5))]);
};

[@react.component]
let make = (~dark=true, ~cbClickToggleBtn=_ => ()) => {
  <header className={Styles.container(~acDark=dark)}>
    <div
      className={Styles.box(
        ~acOverrides=[
          Css.paddingRight(Css.px(30)),
          Css.minWidth(Css.px(238)),
        ],
      )}>
      <ACTooltip label="Toggle">
        <ACBtn
          onClick=cbClickToggleBtn
          color={dark ? Css.hex("fff") : Css.hex("202124")}
          overrides=[
            Css.marginLeft(Css.px(10)),
            Css.marginRight(Css.px(10)),
          ]>
          <ACIcon name="menu" />
        </ACBtn>
      </ACTooltip>
      <ACTooltip label="Gmail">
        <img
          className=Styles.logo
          src={dark ? "/assets/logo.png" : "/assets/logo-light.png"}
          alt="Logo"
        />
      </ACTooltip>
    </div>
    <ACFilter dark />
    <div className={Styles.box(~acOverrides=[])}>
      <ACTooltip label="Applications">
        <ACBtn
          color={dark ? Css.hex("fff") : Css.hex("202124")}
          overrides=[Css.marginLeft(Css.px(10))]>
          <ACIcon name="apps" />
        </ACBtn>
      </ACTooltip>
      <ACTooltip label="Notifications">
        <ACBtn
          overrides=[
            Css.marginRight(Css.px(10)),
            Css.marginLeft(Css.px(10)),
          ]>
          <ACBadge count=42 />
        </ACBtn>
      </ACTooltip>
      <ACTooltip label="Reason s2">
        <ACBtn
          overrides=[
            Css.marginLeft(Css.px(10)),
            Css.marginRight(Css.px(10)),
          ]>
          <ACAvatar url="/assets/profile.jpg" />
        </ACBtn>
      </ACTooltip>
    </div>
  </header>;
};