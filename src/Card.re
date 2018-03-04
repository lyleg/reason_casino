Random.self_init();

type value =
  | Two
  | Three
  | Four
  | Five
  | Six
  | Seven
  | Eight
  | Nine
  | Ten
  | Jack
  | Queen
  | King
  | Ace;

let values = [Two, Three, Four, Five, Six, Seven, Eight, Nine, Ten, Jack, Queen, King, Ace];

type suit =
  | Diamonds
  | Spades
  | Hearts
  | Clubs;

let suits = [Diamonds, Spades, Hearts, Clubs];

type comaprison =
  | Higher
  | Lower
  | Tie;

type card = (value, suit);

let strFromValue = (value) =>
  switch value {
  | Two => "2"
  | Three => "3"
  | Four => "4"
  | Five => "5"
  | Six => "6"
  | Seven => "7"
  | Eight => "8"
  | Nine => "9"
  | Ten => "10"
  | Jack => "11"
  | Queen => "Q"
  | King => "K"
  | Ace => "A"
  };

let intFromValue = (value) =>
  switch value {
  | Two => 2
  | Three => 3
  | Four => 4
  | Five => 5
  | Six => 6
  | Seven => 7
  | Eight => 8
  | Nine => 9
  | Ten => 10
  | Jack => 11
  | Queen => 12
  | King => 13
  | Ace => 14
  };

let strFromSuit = (suit) =>
  switch suit {
  | Diamonds => "Diamonds"
  | Spades => "Spades"
  | Hearts => "Hearts"
  | Clubs => "Clubs"
  };

let printCard = (card) => {
  let (value, suit) = card;
  strFromValue(value) ++ " " ++ strFromSuit(suit)
};

let compareCard = (card1, card2) => {
  let (value1, _suit1) = card1;
  let (value2, _suit2) = card2;
  let intValue1 = intFromValue(value1);
  let intValue2 = intFromValue(value2);
  switch (compare(intValue1, intValue2)) {
  | 1 => Higher
  | (-1) => Lower
  | (-0) => Tie
  | _ => Tie
  }
};