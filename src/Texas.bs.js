// Generated by BUCKLESCRIPT VERSION 2.2.3, PLEASE EDIT WITH CARE
'use strict';

var Block = require("bs-platform/lib/js/block.js");
var Curry = require("bs-platform/lib/js/curry.js");
var React = require("react");
var ReasonReact = require("reason-react/src/ReasonReact.js");
var Player$ReactTemplate = require("./Player.bs.js");
var TexasGame$ReactTemplate = require("./TexasGame.bs.js");
var PokerStats$ReactTemplate = require("./components/PokerStats.bs.js");
var PokerPrompt$ReactTemplate = require("./components/PokerPrompt.bs.js");
var PrintPlayers$ReactTemplate = require("./components/PrintPlayers.bs.js");

var component = ReasonReact.reducerComponent("Texas");

function make() {
  var newrecord = component.slice();
  newrecord[/* render */9] = (function (self) {
      var round = TexasGame$ReactTemplate.stringFromRound(self[/* state */2][/* round */2]);
      return React.createElement("div", undefined, ReasonReact.element(/* None */0, /* None */0, PrintPlayers$ReactTemplate.make(self[/* state */2][/* players */1], self[/* state */2][/* dealer */3], /* array */[])), ReasonReact.element(/* None */0, /* None */0, PokerPrompt$ReactTemplate.make(self[/* state */2][/* round */2], (function (action) {
                            return Curry._1(self[/* send */4], action);
                          }), /* array */[])), ReasonReact.element(/* None */0, /* None */0, PokerStats$ReactTemplate.make(round, self[/* state */2][/* players */1], self[/* state */2][/* pool */4], /* array */[])));
    });
  newrecord[/* initialState */10] = (function () {
      return /* record */[
              /* deck : [] */0,
              /* players : :: */[
                /* record */[
                  /* id */1,
                  /* hand : [] */0,
                  /* money */1000,
                  /* name */"John",
                  /* src : Computer */1
                ],
                /* :: */[
                  /* record */[
                    /* id */2,
                    /* hand : [] */0,
                    /* money */1000,
                    /* name */"Lyle",
                    /* src : Human */0
                  ],
                  /* [] */0
                ]
              ],
              /* round : PreFlop */0,
              /* dealer : record */[
                /* id */1,
                /* hand : [] */0,
                /* money */0,
                /* name */"Dealer",
                /* src : Computer */1
              ],
              /* pool */0
            ];
    });
  newrecord[/* reducer */12] = (function (action, state) {
      var exit = 0;
      if (typeof action === "number") {
        var match = TexasGame$ReactTemplate.deal(state[/* players */1]);
        return /* Update */Block.__(0, [/* record */[
                    /* deck */match[0],
                    /* players */match[1],
                    /* round : Flop */1,
                    /* dealer */state[/* dealer */3],
                    /* pool */state[/* pool */4]
                  ]]);
      } else {
        switch (action.tag | 0) {
          case 0 : 
              var player1Prompt = Player$ReactTemplate.randomBot(1);
              var player2Prompt_001 = /* prompt */action[0];
              var player2Prompt = /* record */[
                /* id */2,
                player2Prompt_001
              ];
              var prompts_001 = /* :: */[
                player2Prompt,
                /* [] */0
              ];
              var prompts = /* :: */[
                player1Prompt,
                prompts_001
              ];
              var match$1 = Player$ReactTemplate.processPlayers(/* [] */0, state[/* players */1], state[/* dealer */3], prompts);
              var players = match$1[0];
              var board_000 = state[/* deck */0];
              var board = /* tuple */[
                board_000,
                players
              ];
              var match$2 = TexasGame$ReactTemplate.dealToPlayers(board, players, 1);
              return /* Update */Block.__(0, [/* record */[
                          /* deck */match$2[0],
                          /* players */match$2[1],
                          /* round : Middle */2,
                          /* dealer */match$1[1],
                          /* pool */state[/* pool */4]
                        ]]);
          case 1 : 
          case 2 : 
              exit = 1;
              break;
          
        }
      }
      if (exit === 1) {
        return /* Update */Block.__(0, [/* record */[
                    /* deck */state[/* deck */0],
                    /* players */state[/* players */1],
                    /* round : Middle */2,
                    /* dealer */state[/* dealer */3],
                    /* pool */state[/* pool */4]
                  ]]);
      }
      
    });
  return newrecord;
}

exports.component = component;
exports.make = make;
/* component Not a pure module */
