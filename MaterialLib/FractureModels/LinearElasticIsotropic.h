/**
 * \copyright
 * Copyright (c) 2012-2016, OpenGeoSys Community (http://www.opengeosys.org)
 *            Distributed under a Modified BSD License.
 *              See accompanying file LICENSE.txt or
 *              http://www.opengeosys.org/project/license
 *
 */

#ifndef MATERIALLIB_FRACTURE_LINEARELASTICISOTROPIC_H_
#define MATERIALLIB_FRACTURE_LINEARELASTICISOTROPIC_H_

#include <Eigen/Eigen>

#include "ProcessLib/Parameter/Parameter.h"

#include "FractureModelBase.h"

namespace MaterialLib
{
namespace Fracture
{

template <int DisplacementDim>
class LinearElasticIsotropic final : public FractureModelBase<DisplacementDim>
{
public:
    /// Variables specific to the material model
    struct MaterialProperties
    {
        using P = ProcessLib::Parameter<double>;
        using X = ProcessLib::SpatialPosition;

        MaterialProperties(P const& normal_stiffness_, P const& shear_stiffness_)
            : normal_stiffness(normal_stiffness_), shear_stiffness(shear_stiffness_)
        {
        }

        P const& normal_stiffness;
        P const& shear_stiffness;
    };

public:
    explicit LinearElasticIsotropic(
        MaterialProperties const& material_properties)
        : _mp(material_properties)
    {
    }

    void computeConstitutiveRelation(
            double const t,
            ProcessLib::SpatialPosition const& x,
            Eigen::Ref<Eigen::VectorXd const> w_prev,
            Eigen::Ref<Eigen::VectorXd const> w,
            Eigen::Ref<Eigen::VectorXd const> sigma_prev,
            Eigen::Ref<Eigen::VectorXd> sigma,
            Eigen::Ref<Eigen::MatrixXd> C) override;

private:
    MaterialProperties _mp;
};

}  // namespace Fracture
}  // namespace MaterialLib

namespace MaterialLib
{
namespace Fracture
{
extern template class LinearElasticIsotropic<2>;
extern template class LinearElasticIsotropic<3>;
}  // namespace Fractrue
}  // namespace MaterialLib

#endif
