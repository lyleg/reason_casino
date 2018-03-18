// Generated by BUCKLESCRIPT VERSION 2.1.0, PLEASE EDIT WITH CARE
'use strict';

var List               = require("bs-platform/lib/js/list.js");
var $$Array            = require("bs-platform/lib/js/array.js");
var React              = require("react");
var Pervasives         = require("bs-platform/lib/js/pervasives.js");
var ReasonReact        = require("reason-react/src/ReasonReact.js");
var Hand$ReactTemplate = require("./Hand.bs.js");

var component = ReasonReact.statelessComponent("PrintPlayers");

function make(players, dealer, _) {
  var newrecord = component.slice();
  newrecord[/* render */9] = (function () {
      return React.createElement("div", {
                  style: {
                    color: "#444444",
                    fontSize: "22px"
                  }
                }, React.createElement("h1", undefined, "Players"), $$Array.of_list(List.mapi((function (idx, player) {
                            return React.createElement("div", {
                                        key: Pervasives.string_of_int(idx),
                                        style: {
                                          marginBottom: "20px"
                                        }
                                      }, player[/* name */3], " (" + (Pervasives.string_of_int(player[/* id */0]) + ")"), " (" + (Pervasives.string_of_int(player[/* money */2]) + ")"), ReasonReact.element(/* None */0, /* None */0, Hand$ReactTemplate.make(player[/* hand */1], /* array */[])));
                          }), players)), React.createElement("h1", undefined, "Dealer"), " (" + (Pervasives.string_of_int(dealer[/* money */2]) + ")"), ReasonReact.element(/* None */0, /* None */0, Hand$ReactTemplate.make(dealer[/* hand */1], /* array */[])));
    });
  return newrecord;
}

exports.component = component;
exports.make      = make;
/* component Not a pure module */
