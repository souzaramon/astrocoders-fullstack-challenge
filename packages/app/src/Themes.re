open Types;

let sky = {
  dark: true,
  background: Css.backgroundImage(Css.url("/assets/bg.jpg")),
};

let light = {dark: false, background: Css.backgroundColor(Css.hex("fff"))};

let dark = {dark: true, background: Css.backgroundColor(Css.hex("111"))};
