module Styles = {
  open Css;

  let container =
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
let make = (~tweet) => {
  <div className=Styles.container>
    <img src="/assets/twitter-card.jpg" alt="card twitter" />
    <h3>
      {React.string(tweet##user##screen_name)}
      <small>
        {React.string(
           " - " ++ Utils.fromISOStringToLocale(tweet##created_at),
         )}
      </small>
    </h3>
    <p> {React.string(tweet##text)} </p>
  </div>;
};
