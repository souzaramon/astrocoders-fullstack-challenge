open Types;

module Styles = {
  open Css;

  let container =
    style([display(flexBox), width(pct(100.0)), height(pct(100.0))]);

  let box = (~acOverrides) =>
    merge([
      style([display(flexBox), width(pct(100.0)), height(pct(100.0))]),
      style(acOverrides),
    ]);
};

[@react.component]
let make = (~theme) => {
  <LayoutBase theme>
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
          <ACTooltip label="Select">
            <ACCheckBox
              value=ACCheckBox.UnChecked
              color={theme.dark ? Css.hex("fff") : Css.hex("202124")}
            />
          </ACTooltip>
          <ACTooltip label="Refresh">
            <ACBtn
              color={theme.dark ? Css.hex("fff") : Css.hex("202124")}
              overrides=[Css.marginLeft(Css.px(10))]>
              <ACIcon name="refresh" />
            </ACBtn>
          </ACTooltip>
          <ACBtn
            color={theme.dark ? Css.hex("fff") : Css.hex("202124")}
            overrides=[Css.marginLeft(Css.px(10))]>
            <ACIcon name="more_vert" />
          </ACBtn>
        </header>
        <ACScrollable
          dark={theme.dark}
          overrides=[
            Css.display(Css.flexBox),
            Css.flexDirection(Css.column),
          ]>
          <ACTabs />
          <ACListEmails emails=Mock.emails />
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
    </div>
  </LayoutBase>;
};