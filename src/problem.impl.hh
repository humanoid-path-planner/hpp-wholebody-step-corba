// Copyright (C) 2011,2012,2013,2014 CNRS-LAAS
// Author: Florent Lamiraux.
//
// This file is part of the hpp-wholebody-step-corba.
//
// hpp-wholebody-step-corba is free software: you can redistribute
// it and/or modify it under the terms of the GNU Lesser General
// Public License as published by the Free Software Foundation, either
// version 3 of the License, or (at your option) any later version.
//
// hpp-wholebody-step-corba is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU Lesser General Public License for more details.
//
// You should have received a copy of the GNU Lesser General Public
// License along with hpp-wholebody-step-corba.  If not, see
// <http://www.gnu.org/licenses/>.

#ifndef HPP_WHOLEBODY_STEP_CORBA_WHOLEBODY_STEP_HH
# define HPP_WHOLEBODY_STEP_CORBA_WHOLEBODY_STEP_HH

# include <omniORB4/CORBA.h>
# include <hpp/corbaserver/wholebody-step/fwd.hh>
# include <hpp/corbaserver/wholebody-step/problem.hh>

namespace hpp {
  namespace wholebodyStep {
    namespace impl {
      class Problem : public virtual
      POA_hpp::corbaserver::wholebody_step::Problem
      {
      public:
        typedef hpp::corbaserver::wholebody_step::Problem::StaticStabilityType
          StaticStabilityType;

	Problem ();

	void setServer (Server* server)
        {
          server_ = server;
        }

	virtual void addStaticStabilityConstraints
	(const char* prefix, const hpp::floatSeq& floatArray,
	 const char* leftAnkle, const char* rightAnkle, const char* comName,
         const StaticStabilityType type)
        throw (hpp::Error);

      private:
	core::ProblemSolverPtr_t problemSolver();
        Server* server_;
      }; // class WholebodyStep
    } // namespace impl
  } // namespace wholebodyStep
} // namespace hpp

#endif //HPP_WHOLEBODY_STEP_CORBA_WHOLEBODY_STEP_HH
