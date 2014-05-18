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

#ifndef UCMP_MISC_DIAGNOSTIC_HH
# define UCMP_MISC_DIAGNOSTIC_HH

# include <ucmp/misc/location.hh>

namespace ucmp
{
    namespace misc
    {
        class Diagnostic
        {
            public:
                enum Type
                {
                    none = 0,
                    internal = 1,
                    scan = 2,
                    parse = 3,
                    bind = 4,
                    type = 5,
                    analysis = 6,
                };

                enum Severity
                {
                    warn,
                    err,
                    critical,
                };

            public:
                Diagnostic(Severity s,
                           Type t,
                           const std::string &msg,
                           const ucmp::misc::location& loc)
                    : s_(s)
                    , t_(t)
                    , msg_(msg)
                    , loc_(loc)
                {}

                Diagnostic()
                {}

                Severity severity_get() const
                {
                    return s_;
                }

                Type type_get() const
                {
                    return t_;
                }

                const std::string& msg_get() const
                {
                    return msg_;
                }

                const ucmp::misc::location& location_get() const
                {
                    return loc_;
                }

                void severity_set(Severity s)
                {
                    s_ = s;
                }

                Diagnostic& operator<<(Severity s)
                {
                    s_ = s;

                    return *this;
                }

                Diagnostic& operator<<(Type t)
                {
                    t_ = t;

                    return *this;
                }

                Diagnostic& operator<<(const std::string& msg)
                {
                    msg_ += msg;

                    return *this;
                }

                Diagnostic& operator<<(const ucmp::misc::location& loc)
                {
                    loc_ = loc;

                    return *this;
                }

            private:
                Severity s_;
                Type t_;
                std::string msg_;
                ucmp::misc::location loc_;
        };
    } // namespace misc
} // namespace ucmp

#endif /* !UCMP_MISC_DIAGNOSTIC_HH */
