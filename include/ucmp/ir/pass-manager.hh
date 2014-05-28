/*
Copyright (C) 2014 Baptiste Covolato <b.covolato@gmail.com>

This program is free software; you can redistribute it and/or
modify it under the terms of the GNU General Public License
as published by the Free Software Foundation; either version 2
of the License, or (at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program; if not, write to the Free Software
Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
*/

#ifndef UCMP_IR_PASS_MANAGER_HH
# define UCMP_IR_PASS_MANAGER_HH

# include <memory>
# include <list>

# include <ucmp/ir/pass.hh>

namespace ucmp
{
    namespace ir
    {
        class PassManager
        {
            public:
                PassManager() = default;
                virtual ~PassManager() = default;
        };

        class UnitPassManager : public PassManager
        {
            public:
                UnitPassManager() = default;
                virtual ~UnitPassManager() = default;

                void add(UnitPass* p)
                {
                    passes_.push_back(std::unique_ptr<UnitPass>(p));
                }

                void run(Unit& u);

            protected:
                std::list<std::unique_ptr<UnitPass>> passes_;
        };

        class FunctionPassManager : public PassManager
        {
            public:
                FunctionPassManager() = default;
                virtual ~FunctionPassManager() = default;

                void add(FunctionPass* p)
                {
                    passes_.push_back(std::unique_ptr<FunctionPass>(p));
                }

                void run(Function& f);

            protected:
                std::list<std::unique_ptr<FunctionPass>> passes_;
        };
    } // namespace ir
} // namespace ucmp

#endif /* !PASS_MANAGER_HH */
