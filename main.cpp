#include <mata/nfa/nfa.hh>
#include <mata/utils/ord-vector.hh>

using namespace mata::nfa;

int main(int agrc, char **argv) {
  Nfa aut1, aut2;

  aut1.initial = {1};
  aut1.final = {2};
  aut1.delta.add(1, 0, 2);

  aut2.initial = {1};
  aut2.final = {2};
  aut2.delta.add(1, 1, 2);

  // aut1.unite_nondet_with(aut2);

  aut1.trim(); // important to not spawn non existing states during complement
  aut1.complement_deterministic(mata::utils::OrdVector<mata::Symbol>());

  aut1.print_to_dot(std::cout);

  return 0;
}
