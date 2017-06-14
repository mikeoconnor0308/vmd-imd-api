#include "CppUnitTest.h"
#include "imd.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace VMDIMDUnitTests
{
  TEST_CLASS(TestIMDSerialization)
  {
  public:

    TEST_METHOD(TestEnergiesSerialization)
    {
      IMDEnergies energies;
      energies.tstep = 1000;
      energies.T = 10.0f;          /**< Temperature in degrees Kelvin             */
      energies.Etot = 10.0f;       /**< Total energy, in Kcal/mol                 */
      energies.Epot = 10.0f;       /**< Potential energy, in Kcal/mol             */
      energies.Evdw = 2000.0f;       /**< Van der Waals energy, in Kcal/mol         */
      energies.Eelec = 10.0f;      /**< Electrostatic energy, in Kcal/mol         */
      energies.Ebond = -10.0f;      /**< Bond energy, Kcal/mol                     */
      energies.Eangle = -10.0f;     /**< Angle energy, Kcal/mol                    */
      energies.Edihe = 10.0f;      /**< Dihedral energy, Kcal/mol                 */
      energies.Eimpr = -10.0f;      /**< Improper energy, Kcal/mol                 */

      auto buf = static_cast<char *>(malloc(IMDENERGIESSIZE));

      auto ptr = imd_serialize_energies(buf, &energies);

      IMDEnergies recv_buf;

      auto recv_ptr = imd_deserialize_energies(buf, &recv_buf);

      Assert::AreEqual(energies.tstep, recv_buf.tstep);
      Assert::AreEqual(energies.T, recv_buf.T);
      Assert::AreEqual(energies.Etot, recv_buf.Etot);
      Assert::AreEqual(energies.Epot, recv_buf.Epot);
      Assert::AreEqual(energies.Evdw, recv_buf.Evdw);
      Assert::AreEqual(energies.Eelec, recv_buf.Eelec);
      Assert::AreEqual(energies.Ebond, recv_buf.Ebond);
      Assert::AreEqual(energies.Eangle, recv_buf.Eangle);
      Assert::AreEqual(energies.Edihe, recv_buf.Edihe);
      Assert::AreEqual(energies.Eimpr, recv_buf.Eimpr);
    }
  };
}