#include <mata/nfa/nfa.hh>
#include <mata/utils/ord-vector.hh>

using namespace mata::nfa;

typedef unsigned long ul;

int main(int agrc, char **argv) {
  Nfa aut1, aut2;

  // automata for 2+2y-3z=-2
  std::map<int, unsigned int> mp;
  mp[-1] = 3;
  mp[-2] = 4;

  // out 2
  aut1.delta.add(2, 0b101, 2);
  aut1.delta.add(2, 0b010, 0);
  aut1.delta.add(2, 0b000, 1);
  aut1.delta.add(2, 0b111, 1);

  // out 0
  aut1.delta.add(0, 0b000, 0);
  aut1.delta.add(0, 0b111, 0);
  aut1.delta.add(0, 0b101, 1);
  aut1.delta.add(0, 0b010, mp[-1]);

  // out 1
  aut1.delta.add(1, 0b011, 1);
  aut1.delta.add(1, 0b001, 2);
  aut1.delta.add(1, 0b100, 0);
  aut1.delta.add(1, 0b110, mp[-1]);

  // out -1
  aut1.delta.add(mp[-1], 0b100, mp[-1]);
  aut1.delta.add(mp[-1], 0b001, 1);
  aut1.delta.add(mp[-1], 0b011, 0);
  aut1.delta.add(mp[-1], 0b110, mp[-2]);

  // out -2
  aut1.delta.add(mp[-2], 0b010, mp[-2]);
  aut1.delta.add(mp[-2], 0b000, mp[-1]);
  aut1.delta.add(mp[-2], 0b111, mp[-1]);
  aut1.delta.add(mp[-2], 0b101, 0);

  aut1.initial = {2};
  aut1.final = {0};

  aut2.initial = {1};
  aut2.final = {2};
  aut2.delta.add(1, 1, 2);

  aut1.trim(); // important to not spawn non existing states during
  // complement
  // aut1.complement_deterministic(mata::utils::OrdVector<mata::Symbol>());

  std::cout << aut1.is_lang_empty() << std::endl;

  return 0;
}
