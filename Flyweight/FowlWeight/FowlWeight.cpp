// The number of birds migrating to Objective has overwhelmed the Quackologists
// who are complaining that it is hard to keep up because the journaling program
// you wrote is getting sluggish. Quackologists capture birds, categorize them,
// weight them, tag them, and finally, record them with your program. After
// hours of drinking coffee at Starbuzz reviewing your design, you realize that
// some traits are common to each type of bird; its type, the sound it makes and
// how it swims. If only you could isolate the common (intrinsic) traits from
// the unique (extrinsic) traits, its weight and tag number. Your redesign
// implements the ‘Flyweight?pattern by creating a single instance for each type
// of bird and each bird contains a reference back to its type.

#include "FowlWeight.hpp"
#include <algorithm>
#include <iostream>
#include <vector>

using namespace HeadFirstDesignPatterns::FlyWeight::FowlWeight;

namespace {
const int MAX_BIRDS = 100;
const double MIN_WIEGHT = 0.1;
}  // namespace

int main() {
    FowlFactory fowlFactory;

    // Create a flock of mixed birds with random weights and tag them with a
    // number

    std::vector<std::shared_ptr<Bird>> flock;
    flock.resize(MAX_BIRDS);

    srand(42);
    for (int i = 0; i < MAX_BIRDS; i++) {
        auto type = static_cast<Fowl::type>(rand() %
                                            static_cast<int>(Fowl::type::last));
        double weight = (rand() % 100) * MIN_WIEGHT;
        if (weight < MIN_WIEGHT) {
            weight = MIN_WIEGHT;
        }
        flock[i] = fowlFactory.getBird(type, i, weight);
    }

    //	Sort flock by ascending weight and display a journal

    std::sort(
        flock.begin(), flock.end(),
        [](const std::shared_ptr<Bird>& lhs, const std::shared_ptr<Bird>& rhs) {
            return lhs->getWeight() < rhs->getWeight();
        });

    for (const auto& bird : flock) {
        std::cout << bird->toString();
        std::cout << ", says \"";
        bird->quack();
        std::cout << "\" and ";
        bird->swim();
        std::cout << std::endl;
    }

    return EXIT_SUCCESS;
}

// Output:
/*
Bird #1, weighs 0.1 pounds, is a Mallard Duck, says "Quack" and swims
Bird #28, weighs 0.2 pounds, is a Rubber Duck, says "Squeak" and floats
Bird #34, weighs 0.5 pounds, is a Mallard Duck, says "Quack" and swims
Bird #12, weighs 0.7 pounds, is a Redhead Duck, says "Quack" and swims
Bird #59, weighs 0.7 pounds, is a Redhead Duck, says "Quack" and swims
Bird #81, weighs 0.7 pounds, is a Mallard Duck, says "Quack" and swims
Bird #70, weighs 1 pounds, is a Wild Turkey, says "Gobble gobble" and struts
Bird #9, weighs 1.2 pounds, is a Model duck, says "<< Silence >>" and sinks
Bird #53, weighs 1.2 pounds, is a Mallard Duck, says "Quack" and swims
Bird #91, weighs 1.2 pounds, is a Redhead Duck, says "Quack" and swims
Bird #39, weighs 1.3 pounds, is a Wild Turkey, says "Gobble gobble" and struts
Bird #48, weighs 1.4 pounds, is a Rubber Duck, says "Squeak" and floats
Bird #57, weighs 1.4 pounds, is a Mallard Duck, says "Quack" and swims
Bird #15, weighs 1.5 pounds, is a Mallard Duck, says "Quack" and swims
Bird #86, weighs 1.5 pounds, is a Rubber Duck, says "Squeak" and floats
Bird #60, weighs 1.7 pounds, is a Model duck, says "<< Silence >>" and sinks
Bird #47, weighs 1.7 pounds, is a Rubber Duck, says "Squeak" and floats
Bird #51, weighs 1.8 pounds, is a Rubber Duck, says "Squeak" and floats
Bird #90, weighs 1.9 pounds, is a Mallard Duck, says "Quack" and swims
Bird #99, weighs 2 pounds, is a Mallard Duck, says "Quack" and swims
Bird #41, weighs 2.3 pounds, is a Wild Turkey, says "Gobble gobble" and struts
Bird #21, weighs 2.3 pounds, is a Wild Turkey, says "Gobble gobble" and struts
Bird #26, weighs 2.3 pounds, is a Rubber Duck, says "Squeak" and floats
Bird #62, weighs 2.5 pounds, is a Rubber Duck, says "Squeak" and floats
Bird #8, weighs 2.5 pounds, is a Redhead Duck, says "Quack" and swims
Bird #54, weighs 2.6 pounds, is a Wild Turkey, says "Gobble gobble" and struts
Bird #88, weighs 2.8 pounds, is a Redhead Duck, says "Quack" and swims
Bird #71, weighs 2.8 pounds, is a Redhead Duck, says "Quack" and swims
Bird #69, weighs 3 pounds, is a Rubber Duck, says "Squeak" and floats
Bird #11, weighs 3 pounds, is a Rubber Duck, says "Squeak" and floats
Bird #29, weighs 3 pounds, is a Mallard Duck, says "Quack" and swims
Bird #52, weighs 3.3 pounds, is a Rubber Duck, says "Squeak" and floats
Bird #45, weighs 3.3 pounds, is a Rubber Duck, says "Squeak" and floats
Bird #31, weighs 3.5 pounds, is a Redhead Duck, says "Quack" and swims
Bird #25, weighs 3.6 pounds, is a Mallard Duck, says "Quack" and swims
Bird #74, weighs 3.6 pounds, is a Model duck, says "<< Silence >>" and sinks
Bird #84, weighs 3.8 pounds, is a Rubber Duck, says "Squeak" and floats
Bird #13, weighs 4 pounds, is a Mallard Duck, says "Quack" and swims
Bird #96, weighs 4 pounds, is a Model duck, says "<< Silence >>" and sinks
Bird #44, weighs 4 pounds, is a Redhead Duck, says "Quack" and swims
Bird #79, weighs 4.1 pounds, is a Mallard Duck, says "Quack" and swims
Bird #4, weighs 4.4 pounds, is a Redhead Duck, says "Quack" and swims
Bird #17, weighs 4.5 pounds, is a Model duck, says "<< Silence >>" and sinks
Bird #38, weighs 4.5 pounds, is a Rubber Duck, says "Squeak" and floats
Bird #80, weighs 4.6 pounds, is a Model duck, says "<< Silence >>" and sinks
Bird #18, weighs 4.7 pounds, is a Redhead Duck, says "Quack" and swims
Bird #50, weighs 4.8 pounds, is a Rubber Duck, says "Squeak" and floats
Bird #24, weighs 4.9 pounds, is a Redhead Duck, says "Quack" and swims
Bird #6, weighs 5 pounds, is a Wild Turkey, says "Gobble gobble" and struts
Bird #87, weighs 5 pounds, is a Model duck, says "<< Silence >>" and sinks
Bird #20, weighs 5.5 pounds, is a Rubber Duck, says "Squeak" and floats
Bird #2, weighs 5.6 pounds, is a Wild Turkey, says "Gobble gobble" and struts
Bird #43, weighs 5.8 pounds, is a Rubber Duck, says "Squeak" and floats
Bird #97, weighs 6.1 pounds, is a Rubber Duck, says "Squeak" and floats
Bird #76, weighs 6.1 pounds, is a Wild Turkey, says "Gobble gobble" and struts
Bird #64, weighs 6.2 pounds, is a Model duck, says "<< Silence >>" and sinks
Bird #58, weighs 6.4 pounds, is a Model duck, says "<< Silence >>" and sinks
Bird #42, weighs 6.4 pounds, is a Model duck, says "<< Silence >>" and sinks
Bird #55, weighs 6.5 pounds, is a Wild Turkey, says "Gobble gobble" and struts
Bird #49, weighs 6.6 pounds, is a Model duck, says "<< Silence >>" and sinks
Bird #78, weighs 6.6 pounds, is a Model duck, says "<< Silence >>" and sinks
Bird #37, weighs 6.7 pounds, is a Mallard Duck, says "Quack" and swims
Bird #46, weighs 6.7 pounds, is a Redhead Duck, says "Quack" and swims
Bird #22, weighs 6.8 pounds, is a Model duck, says "<< Silence >>" and sinks
Bird #5, weighs 6.9 pounds, is a Wild Turkey, says "Gobble gobble" and struts
Bird #30, weighs 6.9 pounds, is a Rubber Duck, says "Squeak" and floats
Bird #27, weighs 7 pounds, is a Wild Turkey, says "Gobble gobble" and struts
Bird #92, weighs 7.1 pounds, is a Wild Turkey, says "Gobble gobble" and struts
Bird #77, weighs 7.1 pounds, is a Mallard Duck, says "Quack" and swims
Bird #73, weighs 7.1 pounds, is a Rubber Duck, says "Squeak" and floats
Bird #32, weighs 7.1 pounds, is a Model duck, says "<< Silence >>" and sinks
Bird #67, weighs 7.2 pounds, is a Wild Turkey, says "Gobble gobble" and struts
Bird #82, weighs 7.2 pounds, is a Model duck, says "<< Silence >>" and sinks
Bird #19, weighs 7.2 pounds, is a Wild Turkey, says "Gobble gobble" and struts
Bird #94, weighs 7.2 pounds, is a Wild Turkey, says "Gobble gobble" and struts
Bird #61, weighs 7.3 pounds, is a Model duck, says "<< Silence >>" and sinks
Bird #83, weighs 7.4 pounds, is a Mallard Duck, says "Quack" and swims
Bird #93, weighs 7.4 pounds, is a Wild Turkey, says "Gobble gobble" and struts
Bird #36, weighs 7.6 pounds, is a Rubber Duck, says "Squeak" and floats
Bird #10, weighs 7.6 pounds, is a Redhead Duck, says "Quack" and swims
Bird #3, weighs 7.9 pounds, is a Model duck, says "<< Silence >>" and sinks
Bird #75, weighs 7.9 pounds, is a Redhead Duck, says "Quack" and swims
Bird #40, weighs 7.9 pounds, is a Rubber Duck, says "Squeak" and floats
Bird #95, weighs 7.9 pounds, is a Mallard Duck, says "Quack" and swims
Bird #72, weighs 8.4 pounds, is a Wild Turkey, says "Gobble gobble" and struts
Bird #66, weighs 8.5 pounds, is a Mallard Duck, says "Quack" and swims
Bird #65, weighs 8.5 pounds, is a Rubber Duck, says "Squeak" and floats
Bird #33, weighs 8.6 pounds, is a Rubber Duck, says "Squeak" and floats
Bird #100, weighs 8.7 pounds, is a Mallard Duck, says "Quack" and swims
Bird #68, weighs 8.8 pounds, is a Rubber Duck, says "Squeak" and floats
Bird #98, weighs 8.8 pounds, is a Mallard Duck, says "Quack" and swims
Bird #85, weighs 9 pounds, is a Rubber Duck, says "Squeak" and floats
Bird #14, weighs 9.1 pounds, is a Redhead Duck, says "Quack" and swims
Bird #89, weighs 9.3 pounds, is a Redhead Duck, says "Quack" and swims
Bird #63, weighs 9.4 pounds, is a Wild Turkey, says "Gobble gobble" and struts
Bird #35, weighs 9.7 pounds, is a Redhead Duck, says "Quack" and swims
Bird #56, weighs 9.7 pounds, is a Rubber Duck, says "Squeak" and floats
Bird #16, weighs 9.7 pounds, is a Rubber Duck, says "Squeak" and floats
Bird #23, weighs 9.9 pounds, is a Mallard Duck, says "Quack" and swims
Bird #7, weighs 9.9 pounds, is a Redhead Duck, says "Quack" and swims
*/