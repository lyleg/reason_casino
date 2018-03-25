// Generated by BUCKLESCRIPT VERSION 2.2.3, PLEASE EDIT WITH CARE
'use strict';

var List = require("bs-platform/lib/js/list.js");
var Card$ReactTemplate = require("./Card.bs.js");
var Deck$ReactTemplate = require("./Deck.bs.js");
var Caml_builtin_exceptions = require("bs-platform/lib/js/caml_builtin_exceptions.js");

function stringFromRound(round) {
  switch (round) {
    case 0 : 
        return "PreFlop";
    case 1 : 
        return "Flop";
    case 2 : 
        return "Middle";
    case 3 : 
        return "River";
    case 4 : 
        return "End";
    
  }
}

function dealToPlayers(_board, _playersToBeDelt, numCards) {
  while(true) {
    var playersToBeDelt = _playersToBeDelt;
    var board = _board;
    if (playersToBeDelt) {
      var players = board[1];
      var hd = playersToBeDelt[0];
      var match = Deck$ReactTemplate.getCards(/* [] */0, board[0], numCards);
      var deltCards = match[0];
      List.filter((function(hd){
            return function (player) {
              return +(hd[/* id */0] === player[/* id */0]);
            }
            }(hd)))(players);
      var match$1 = List.partition((function(hd){
          return function (player) {
            return +(hd[/* id */0] === player[/* id */0]);
          }
          }(hd)), players);
      var currentPlayer = match$1[0];
      var playerWithNewCard;
      if (currentPlayer) {
        if (currentPlayer[1]) {
          throw [
                Caml_builtin_exceptions.match_failure,
                [
                  "TexasGame.re",
                  43,
                  6
                ]
              ];
        } else {
          var player = currentPlayer[0];
          playerWithNewCard = /* record */[
            /* id */player[/* id */0],
            /* hand */List.append(player[/* hand */1], deltCards),
            /* money */player[/* money */2],
            /* name */player[/* name */3],
            /* src */player[/* src */4]
          ];
        }
      } else {
        playerWithNewCard = /* record */[
          /* id */hd[/* id */0],
          /* hand */deltCards,
          /* money */hd[/* money */2],
          /* name */hd[/* name */3],
          /* src */hd[/* src */4]
        ];
      }
      var newPlayers = List.append(match$1[1], /* :: */[
            playerWithNewCard,
            /* [] */0
          ]);
      var newBoard_000 = match[1];
      var newBoard = /* tuple */[
        newBoard_000,
        newPlayers
      ];
      _playersToBeDelt = playersToBeDelt[1];
      _board = newBoard;
      continue ;
      
    } else {
      return board;
    }
  };
}

function dealToDealer(deck, dealer, numCards) {
  var match = Deck$ReactTemplate.getCards(/* [] */0, deck, numCards);
  var dealerWithNewCard_000 = /* id */dealer[/* id */0];
  var dealerWithNewCard_001 = /* hand */match[0];
  var dealerWithNewCard_002 = /* money */dealer[/* money */2];
  var dealerWithNewCard_003 = /* name */dealer[/* name */3];
  var dealerWithNewCard_004 = /* src */dealer[/* src */4];
  var dealerWithNewCard = /* record */[
    dealerWithNewCard_000,
    dealerWithNewCard_001,
    dealerWithNewCard_002,
    dealerWithNewCard_003,
    dealerWithNewCard_004
  ];
  return /* tuple */[
          match[1],
          dealerWithNewCard
        ];
}

function deal(players) {
  var deck = Deck$ReactTemplate.makeDeck(/* () */0);
  var shuffledDeck = Deck$ReactTemplate.shuffle(deck);
  var board = /* tuple */[
    shuffledDeck,
    /* [] */0
  ];
  return dealToPlayers(board, players, 2);
}

function printPlayers(players) {
  return List.map((function (player) {
                console.log("****** Player " + (String(player[/* id */0]) + " *******"));
                return List.map((function (card) {
                              console.log(Card$ReactTemplate.printCard(card));
                              return /* () */0;
                            }), player[/* hand */1]);
              }), players);
}

exports.stringFromRound = stringFromRound;
exports.dealToPlayers = dealToPlayers;
exports.dealToDealer = dealToDealer;
exports.deal = deal;
exports.printPlayers = printPlayers;
/* Card-ReactTemplate Not a pure module */