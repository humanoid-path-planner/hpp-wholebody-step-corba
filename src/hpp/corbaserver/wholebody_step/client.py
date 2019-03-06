# Copyright (c) 2011 CNRS
# Author: Florent Lamiraux
#
# This file is part of hpp-wholebody-step-corba.
# hpp-wholebody-step-corba is free software: you can redistribute it
# and/or modify it under the terms of the GNU Lesser General Public
# License as published by the Free Software Foundation, either version
# 3 of the License, or (at your option) any later version.
#
# hpp-wholebody-step-corba is distributed in the hope that it will be
# useful, but WITHOUT ANY WARRANTY; without even the implied warranty
# of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
# General Lesser Public License for more details.  You should have
# received a copy of the GNU Lesser General Public License along with
# hpp-wholebody-step-corba.  If not, see
# <http://www.gnu.org/licenses/>.

from omniORB import CORBA
import CosNaming

from hpp.corbaserver.client import _getIIOPurl, Client as _Parent
from hpp.corbaserver.wholebody_step import Problem

class CorbaError(Exception):
    """
    Raised when a CORBA error occurs.
    """
    def __init__(self, value):
        self.value = value
    def __str__(self):
        return repr(self.value)

class Client (_Parent):
  """
  Connect and create clients for hpp-wholebody-step-planner library.
  """
  defaultClients = {
          'problem': Problem,
          }

  def __init__(self, url = None, context = "corbaserver"):
    """
    Initialize CORBA and create default clients.
    """
    self._initOrb (url)
    self._makeClients ("wholebodyStep", self.defaultClients, context)
