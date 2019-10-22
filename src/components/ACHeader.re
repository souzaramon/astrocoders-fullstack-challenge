module Styles = {
  open Css;

  let container =
    style([
      display(flexBox),
      alignItems(center),
      justifyContent(spaceBetween),
      width(pct(100.0)),
      height(px(64)),
      padding(px(8)),
      borderBottom(px(1), solid, rgba(255, 255, 255, 0.1)),
    ]);

  let box = (~acOverrides) =>
    merge([
      style([display(flexBox), alignItems(center)]),
      style(acOverrides),
    ]);

  let logo = style([width(px(109)), height(px(40)), marginTop(px(5))]);
};

[@react.component]
let make = () =>
  <header className=Styles.container>
    <div
      className={Styles.box(
        ~acOverrides=[
          Css.paddingRight(Css.px(30)),
          Css.minWidth(Css.px(238)),
        ],
      )}>
      <ACTooltip text="Toggle">
        <ACBtn
          overrides=[
            Css.marginLeft(Css.px(10)),
            Css.marginRight(Css.px(10)),
          ]>
          <i className="material-icons"> {React.string("menu")} </i>
        </ACBtn>
      </ACTooltip>
      <ACTooltip text="Gmail">
        <img className=Styles.logo src="/assets/logo.png" alt="Logo" />
      </ACTooltip>
    </div>
    <ACFilter />
    <div className={Styles.box(~acOverrides=[])}>
      <ACTooltip text="Applications">
        <ACBtn overrides=[Css.marginLeft(Css.px(10))]>
          <i className="material-icons"> {React.string("apps")} </i>
        </ACBtn>
      </ACTooltip>
      <ACTooltip text="Notifications">
        <ACBtn
          overrides=[
            Css.marginRight(Css.px(10)),
            Css.marginLeft(Css.px(10)),
          ]>
          <ACBadge count=42 />
        </ACBtn>
      </ACTooltip>
      <ACTooltip text="OCaml s2">
        <ACBtn
          overrides=[
            Css.marginLeft(Css.px(10)),
            Css.marginRight(Css.px(10)),
          ]>
          <ACAvatar url="/assets/profile.png" />
        </ACBtn>
      </ACTooltip>
    </div>
  </header>;