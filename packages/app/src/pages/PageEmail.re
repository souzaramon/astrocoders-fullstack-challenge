open Types;

module Styles = {
  open Css;

  let container =
    style([display(flexBox), width(pct(100.0)), height(pct(100.0))]);

  let content =
    style([
      display(flexBox),
      width(pct(100.0)),
      padding(px(30)),
      backgroundColor(white),
    ]);

  let box = (~acOverrides) =>
    merge([
      style([display(flexBox), width(pct(100.0)), height(pct(100.0))]),
      style(acOverrides),
    ]);

  let tweet =
    style([
      display(flexBox),
      flexDirection(column),
      selector(
        "h3",
        [marginBottom(px(15)), selector("small", [fontSize(rem(0.7))])],
      ),
      selector(
        "img",
        [objectFit(contain), height(px(109)), width(px(89))],
      ),
    ]);
};

[@react.component]
let make = (~theme, ~data, ~id) => {
  let tweet = data##tweets |> Js.Array.find(t => t##id === id);

  <div className=Styles.container>
    <div
      className={Styles.box(~acOverrides=[Css.flexDirection(Css.column)])}>
      <header
        className={Styles.box(
          ~acOverrides=[
            Css.height(Css.px(48)),
            Css.alignItems(Css.center),
            Css.borderBottom(
              Css.px(1),
              Css.solid,
              theme.dark
                ? Css.rgba(255, 255, 255, 0.1) : Css.rgba(0, 0, 0, 0.05),
            ),
          ],
        )}>
        <ACTooltip label="Go back">
          <ACBtn
            color={theme.dark ? Css.hex("fff") : Css.hex("202124")}
            onClick={_ => ReasonReactRouter.push("/")}>
            <ACIcon name="arrow_back" />
          </ACBtn>
        </ACTooltip>
      </header>
      <ACScrollable
        dark={theme.dark}
        overrides=[Css.display(Css.flexBox), Css.flexDirection(Css.column)]>
        <div className=Styles.content>
          {switch (tweet) {
           | Some(t) => <ACEMail tweet=t />
           | _ => <span> {React.string("Oops")} </span>
           }}
        </div>
        <ACFooter dark={theme.dark} />
      </ACScrollable>
    </div>
    <div
      className={Styles.box(
        ~acOverrides=[
          Css.width(Css.px(56)),
          Css.borderLeft(
            Css.px(1),
            Css.solid,
            theme.dark
              ? Css.rgba(255, 255, 255, 0.1) : Css.rgba(0, 0, 0, 0.1),
          ),
          Css.media("(max-width: 780px)", [Css.display(Css.none)]),
        ],
      )}
    />
  </div>;
};
