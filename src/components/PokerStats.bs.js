// Generated by BUCKLESCRIPT VERSION 2.2.3, PLEASE EDIT WITH CARE
'use strict';

var React = require("react");
var ReasonReact = require("reason-react/src/ReasonReact.js");

var component = ReasonReact.statelessComponent("PokerStats");

function make(round, _, pool, _$1) {
  var newrecord = component.slice();
  newrecord[/* render */9] = (function () {
      return React.createElement("div", undefined, React.createElement("h2", undefined, "Statz"), React.createElement("div", undefined, React.createElement("h3", undefined, "Pool: "), React.createElement("div", undefined, String(pool))), React.createElement("div", undefined, React.createElement("h3", undefined, "Round: "), React.createElement("div", undefined, round)));
    });
  return newrecord;
}

exports.component = component;
exports.make = make;
/* component Not a pure module */