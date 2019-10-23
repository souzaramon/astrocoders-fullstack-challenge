Css.(
  global(
    "*",
    [
      unsafe("WebkitFontSmoothing", "antialiased"),
      padding(zero),
      margin(zero),
      boxSizing(borderBox),
      fontFamily("Roboto"),
    ],
  ),
  global("html, body, #root", [width(pct(100.0)), height(pct(100.0))]),
);

ReactDOMRe.renderToElementWithId(<App />, "root");