type filter = string;
type state = {filter: string};

type filterAction =
  | FilterOnChange(string);

type theme = {
  background: Css.rule,
  dark: bool,
};
