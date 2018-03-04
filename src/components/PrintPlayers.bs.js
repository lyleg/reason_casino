// Generated by BUCKLESCRIPT VERSION 2.1.0, PLEASE EDIT WITH CARE
'use strict';

var List               = require("bs-platform/lib/js/list.js");
var $$Array            = require("bs-platform/lib/js/array.js");
var React              = require("react");
var Pervasives         = require("bs-platform/lib/js/pervasives.js");
var ReasonReact        = require("reason-react/src/ReasonReact.js");
var Card$ReactTemplate = require("../Card.bs.js");
var Hand$ReactTemplate = require("./Hand.bs.js");

var component = ReasonReact.statelessComponent("PrintPlayers");

function make(players, _) {
  var newrecord = component.slice();
  newrecord[/* render */9] = (function () {
      return React.createElement("div", {
                  style: {
                    color: "#444444",
                    fontSize: "22px"
                  }
                }, React.createElement("h1", undefined, "Players"), $$Array.of_list(List.mapi((function (idx, player) {
                            List.map((function (card) {
                                    console.log(Card$ReactTemplate.printCard(card));
                                    return /* () */0;
                                  }), player[/* hand */1]);
                            return React.createElement("span", {
                                        key: Pervasives.string_of_int(idx)
                                      }, Pervasives.string_of_int(player[/* id */0]), ReasonReact.element(/* None */0, /* None */0, Hand$ReactTemplate.make(player[/* hand */1], /* array */[])));
                          }), players)));
    });
  return newrecord;
}

exports.component = component;
exports.make      = make;
/* component Not a pure module */
