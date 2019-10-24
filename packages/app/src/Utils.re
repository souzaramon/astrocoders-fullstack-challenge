// sorry 4 do this
let fromISOStringToLocale: string => string = [%raw
  {|
  function (iso) {
    return new Date(iso).toLocaleString();
  }
|}
];
