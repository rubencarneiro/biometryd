/*
 * Copyright (C) 2016 Canonical, Ltd.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation; version 3.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 * Authored by: Thomas Voß <thomas.voss@canonical.com>
 *
 */

#ifndef BIOMETRYD_QML_SERVICE_H_
#define BIOMETRYD_QML_SERVICE_H_

#include <biometry/service.h>
#include <biometry/visibility.h>

#include <QObject>

namespace biometry
{
namespace qml
{
/// @cond
class Device;
/// @endcond

/// @brief Service provides a single point of entry for accessing a biometry::Service instance.
class BIOMETRY_DLL_PUBLIC Service : public QObject
{
    Q_OBJECT
    Q_PROPERTY(bool available READ isAvailable NOTIFY availableChanged)
    Q_PROPERTY(biometry::qml::Device* defaultDevice READ defaultDevice CONSTANT)
public:
    /// @brief Service initializes a new instance with impl and parent.
    Service(const std::shared_ptr<biometry::Service>& impl, QObject* parent = nullptr);

    /// @brief defaultDevice returns the default Device instance that should be used for identification.
    Q_INVOKABLE biometry::qml::Device* defaultDevice() const;

    /// @brief isAvailable returns true if the service is available.
    Q_INVOKABLE bool isAvailable() const;

    /// @brief setAavailable adjusts the value of available to value.
    Q_INVOKABLE void setAvailable(bool available);

    /// @brief availableChanged is emitted with the new value of available.
    Q_SIGNAL void availableChanged(bool);

private:
    bool available_;
    std::shared_ptr<biometry::Service> impl_;
    biometry::qml::Device* defaultDevice_;
};
}
}

#endif // BIOMETRYD_QML_SERVICE_H_
