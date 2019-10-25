module Styles = {
  open Css;

  let container =
    style([
      display(flexBox),
      alignItems(center),
      flexDirection(column),
      backgroundColor(white),
      padding(px(20)),
    ]);

  let banner =
    style([
      backgroundColor(hex("5ea9dd")),
      height(px(100)),
      width(pct(100.0)),
      marginBottom(px(20)),
    ]);

  let profilePick =
    style([borderRadius(pct(50.0)), width(px(48)), height(px(48))]);

  let name =
    style([margin(px(10)), fontSize(rem(1.0)), color(hex("111"))]);

  let text = style([padding(px(10)), color(hex("303030"))]);
};

[@react.component]
let make = (~tweet) => {
  <div className=Styles.container>
    <div className=Styles.banner />
    <img
      src=tweet##user##profile_image_url_https
      className=Styles.profilePick
    />
    <h3 className=Styles.name> {React.string(tweet##user##screen_name)} </h3>
    <small>
      {React.string(Utils.fromISOStringToLocale(tweet##created_at))}
    </small>
    <p className=Styles.text> {React.string(tweet##text)} </p>
  </div>;
};
