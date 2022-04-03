#include "../include/Rect.hpp"
#include "../include/Vect.hpp"

#include <algorithm>
#include <cmath>

class Collision {

	public:
		// Observação: IsColliding espera ângulos em radianos!
		// Para usar graus, forneça a sua própria implementação de Rotate,
		// ou transforme os ângulos no corpo de IsColliding.
		static inline bool IsColliding(Rect& a, Rect& b, float angleOfA, float angleOfB) {
			Vect A[] = { Vect( a.x, a.y + a.h ),
						  Vect( a.x + a.w, a.y + a.h ),
						  Vect( a.x + a.w, a.y ),
						  Vect( a.x, a.y )
						};
			Vect B[] = { Vect( b.x, b.y + b.h ),
						  Vect( b.x + b.w, b.y + b.h ),
						  Vect( b.x + b.w, b.y ),
						  Vect( b.x, b.y )
						};

			for (auto& v : A) {
				v = Rotate(v - a.center(), angleOfA) + a.center();
			}

			for (auto& v : B) {
				v = Rotate(v - b.center(), angleOfB) + b.center();
			}

			Vect axes[] = { Norm(A[0] - A[1]), Norm(A[1] - A[2]), Norm(B[0] - B[1]), Norm(B[1] - B[2]) };

			for (auto& axis : axes) {
				float P[4];

				for (int i = 0; i < 4; ++i) P[i] = Dot(A[i], axis);

				float minA = *std::min_element(P, P + 4);
				float maxA = *std::max_element(P, P + 4);

				for (int i = 0; i < 4; ++i) P[i] = Dot(B[i], axis);

				float minB = *std::min_element(P, P + 4);
				float maxB = *std::max_element(P, P + 4);

				if (maxA < minB || minA > maxB)
					return false;
			}

			return true;
		}

	private:

		static inline float Mag(const Vect& p) {
			return std::sqrt(p.x * p.x + p.y * p.y);
		}

		static inline Vect Norm(const Vect& p) {
			return p*(1.f / Mag(p));
		}

		static inline float Dot(const Vect& a, const Vect& b) {
			return a.x * b.x + a.y * b.y;
		}

		static inline Vect Rotate(const Vect& p, float angle) {
			float cs = std::cos(angle), sn = std::sin(angle);
			return Vect ( p.x * cs - p.y * sn, p.x * sn + p.y * cs );
		}
};

// Aqui estão três operadores que sua classe Vect deve precisar, se já não tiver. 
// Se sua classe tiver métodos para Mag, Norm, Dot e/ou Rotate, você pode substituir
// os usos desses métodos por usos dos seus, mas garanta que deem resultados corretos.

// Vect operator+(const Vect& rhs) const {
//    return Vect(x + rhs.x, y + rhs.y);
// }

// Vect operator-(const Vect& rhs) const {
//    return Vect(x - rhs.x, y - rhs.y);
// }

// Vect operator*(const float rhs) const {
//    return Vect(x * rhs, y * rhs);
// }