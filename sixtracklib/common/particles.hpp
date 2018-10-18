#ifndef CXX_SIXTRACKLIB_COMMON_PARTICLES_HPP__
#define CXX_SIXTRACKLIB_COMMON_PARTICLES_HPP__

#if defined( __cplusplus )

#if !defined( SIXTRL_NO_SYSTEM_INCLUDES )
    #include <cstddef>
    #include <cstdint>
    #include <cstdlib>
    #include <utility>

    #include <type_traits>
    #include <iterator>
#endif /* !defined( SIXTRL_NO_SYSTEM_INCLUDES ) */

#if !defined( SIXTRL_NO_INCLUDES )
    #include "sixtracklib/common/definitions.h"
    #include "sixtracklib/common/internal/particles_defines.h"
    #include "sixtracklib/common/particles.h"
    #include "sixtracklib/common/buffer.hpp"
#endif /* !defined( SIXTRL_NO_INCLUDES ) */

namespace SIXTRL_CXX_NAMESPACE
{
    template< typename T >
    struct TParticles
    {
        using num_elements_t = NS(particle_num_elements_t);

        using real_t = typename std::iterator_traits< T* >::value_type;

        using real_pointer_t       = real_t*;
        using const_real_pointer_t = real_t const*;

        using index_t = typename std::iterator_traits<
            NS(particle_index_ptr_t) >::value_type;

        using index_pointer_t       = index_t*;
        using const_index_pointer_t = index_t const*;

        using type_id_t     = NS(object_type_id_t);
        using size_type     = NS(buffer_size_t);
        using buffer_t   	= ::NS(Buffer);

        SIXTRL_FN TParticles() = default;
        SIXTRL_FN TParticles( TParticles< T > const& other ) = default;
        SIXTRL_FN TParticles( TParticles< T >&& other ) = default;

        SIXTRL_FN TParticles< T >& operator=(
            TParticles< T > const& rhs ) = default;

        SIXTRL_FN TParticles< T >& operator=(
            TParticles< T >&& rhs ) = default;

        SIXTRL_FN ~TParticles() = default;

        /* ----------------------------------------------------------------- */

        SIXTRL_FN static bool CanAddToBuffer(
            buffer_t& SIXTRL_RESTRICT_REF buffer,
            size_type const num_particles,
            size_type* SIXTRL_RESTRICT ptr_requ_objects = nullptr,
            size_type* SIXTRL_RESTRICT ptr_requ_slots = nullptr,
            size_type* SIXTRL_RESTRICT ptr_requ_dataptrs = nullptr
        ) SIXTRL_NOEXCEPT;

        SIXTRL_FN static TParticles< T >* CreateNewOnBuffer(
            buffer_t& SIXTRL_RESTRICT_REF buffer, size_type const nparticles );

        SIXTRL_FN static TParticles< T >* AddToBuffer(
            buffer_t& SIXTRL_RESTRICT_REF buffer,
            size_type const num_particles,
            real_pointer_t  q0_ptr            = nullptr,
            real_pointer_t  mass0_ptr         = nullptr,
            real_pointer_t  beta0_ptr         = nullptr,
            real_pointer_t  gamma0_ptr        = nullptr,
            real_pointer_t  p0c_ptr           = nullptr,
            real_pointer_t  s_ptr             = nullptr,
            real_pointer_t  x_ptr             = nullptr,
            real_pointer_t  y_ptr             = nullptr,
            real_pointer_t  px_ptr            = nullptr,
            real_pointer_t  py_ptr            = nullptr,
            real_pointer_t  zeta_ptr          = nullptr,
            real_pointer_t  psigma_ptr        = nullptr,
            real_pointer_t  delta_ptr         = nullptr,
            real_pointer_t  rpp_ptr           = nullptr,
            real_pointer_t  rvv_ptr           = nullptr,
            real_pointer_t  chi_ptr           = nullptr,
            index_pointer_t particle_id_ptr   = nullptr,
            index_pointer_t at_element_id_ptr = nullptr,
            index_pointer_t at_turn_ptr       = nullptr,
            index_pointer_t state_ptr         = nullptr );

        /* ----------------------------------------------------------------- */

        SIXTRL_FN bool copy( TParticles< T > const& other ) SIXTRL_NOEXCEPT;

        SIXTRL_FN bool copySingle( TParticles< T > const& other,
            index_t const source_index,
            index_t dest_index = index_t{ -1 } ) SIXTRL_NOEXCEPT;

        SIXTRL_FN bool copyRange(
            TParticles< T > const& other,
            index_t const src_start_idx,
            index_t const src_end_idx,
            index_t dst_start_idx = index_t{ -1 } ) SIXTRL_NOEXCEPT;

        /* ----------------------------------------------------------------- */

        SIXTRL_FN type_id_t getTypeId() const SIXTRL_NOEXCEPT;
        SIXTRL_FN num_elements_t getNumParticles() const SIXTRL_NOEXCEPT;

        SIXTRL_FN void setNumParticles(
            num_elements_t const num_particles ) SIXTRL_NOEXCEPT;

        SIXTRL_FN void preset() SIXTRL_NOEXCEPT;

        /* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

        SIXTRL_FN const_real_pointer_t getQ0() const SIXTRL_NOEXCEPT;
        SIXTRL_FN real_pointer_t getQ0() SIXTRL_NOEXCEPT;

        SIXTRL_FN real_t getQ0Value(
            index_t const index ) const SIXTRL_NOEXCEPT;

        template< typename Iter >
        SIXTRL_FN void setQ0( Iter begin, Iter end ) SIXTRL_NOEXCEPT;

        SIXTRL_FN void setQ0Value(
            index_t const index, real_t const value ) SIXTRL_NOEXCEPT;

        SIXTRL_FN void assignQ0Ptr( real_pointer_t ptr ) SIXTRL_NOEXCEPT;

        /* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

        SIXTRL_FN const_real_pointer_t getMass0() const SIXTRL_NOEXCEPT;
        SIXTRL_FN real_pointer_t getMass0() SIXTRL_NOEXCEPT;

        SIXTRL_FN real_t getMass0Value(
            index_t const index ) const SIXTRL_NOEXCEPT;

        template< typename Iter >
        SIXTRL_FN void setMass0( Iter begin, Iter end ) SIXTRL_NOEXCEPT;

        SIXTRL_FN void setMass0Value(
            index_t const index, real_t const value ) SIXTRL_NOEXCEPT;

        SIXTRL_FN void assignMass0Ptr( real_pointer_t ptr ) SIXTRL_NOEXCEPT;

        /* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

        SIXTRL_FN const_real_pointer_t getBeta0() const SIXTRL_NOEXCEPT;
        SIXTRL_FN real_pointer_t getBeta0() SIXTRL_NOEXCEPT;

        SIXTRL_FN real_t getBeta0Value(
            index_t const index ) const SIXTRL_NOEXCEPT;

        template< typename Iter >
        SIXTRL_FN void setBeta0( Iter begin, Iter end ) SIXTRL_NOEXCEPT;

        SIXTRL_FN void setBeta0Value(
            index_t const index, real_t const value ) SIXTRL_NOEXCEPT;

        SIXTRL_FN void assignBeta0Ptr( real_pointer_t ptr ) SIXTRL_NOEXCEPT;

        /* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

        SIXTRL_FN const_real_pointer_t getGamma0() const SIXTRL_NOEXCEPT;

        SIXTRL_FN real_pointer_t getGamma0() SIXTRL_NOEXCEPT;

        SIXTRL_FN real_t getGamma0Value(
            index_t const index ) const SIXTRL_NOEXCEPT;

        template< typename Iter >
        SIXTRL_FN void setGamma0( Iter begin, Iter end ) SIXTRL_NOEXCEPT;

        SIXTRL_FN void setGamma0Value(
            index_t const index, real_t const value ) SIXTRL_NOEXCEPT;

        SIXTRL_FN void assignGamma0Ptr( real_pointer_t ptr ) SIXTRL_NOEXCEPT;

        /* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

        SIXTRL_FN const_real_pointer_t getP0c() const SIXTRL_NOEXCEPT;

        SIXTRL_FN real_pointer_t getP0c() SIXTRL_NOEXCEPT;

        SIXTRL_FN real_t getP0cValue(
            index_t const index ) const SIXTRL_NOEXCEPT;

        template< typename Iter >
        SIXTRL_FN void setP0c( Iter begin, Iter end ) SIXTRL_NOEXCEPT;

        SIXTRL_FN void setP0cValue(
            index_t const index, real_t const value ) SIXTRL_NOEXCEPT;

        SIXTRL_FN void assignP0cPtr( real_pointer_t ptr ) SIXTRL_NOEXCEPT;

        /* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

        SIXTRL_FN const_real_pointer_t getS() const SIXTRL_NOEXCEPT;

        SIXTRL_FN real_pointer_t getS() SIXTRL_NOEXCEPT;

        SIXTRL_FN real_t getSValue(
            index_t const index ) const SIXTRL_NOEXCEPT;

        template< typename Iter >
        SIXTRL_FN void setS( Iter begin, Iter end ) SIXTRL_NOEXCEPT;

        SIXTRL_FN void setSValue(
            index_t const index, real_t const value ) SIXTRL_NOEXCEPT;

        SIXTRL_FN void assignSPtr( real_pointer_t ptr ) SIXTRL_NOEXCEPT;

        /* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

        SIXTRL_FN const_real_pointer_t getX() const SIXTRL_NOEXCEPT;

        SIXTRL_FN real_pointer_t getX() SIXTRL_NOEXCEPT;

        SIXTRL_FN real_t getXValue(
            index_t const index ) const SIXTRL_NOEXCEPT;

        template< typename Iter >
        SIXTRL_FN void setX( Iter begin, Iter end ) SIXTRL_NOEXCEPT;

        SIXTRL_FN void setXValue(
            index_t const index, real_t const value ) SIXTRL_NOEXCEPT;

        SIXTRL_FN void assignXPtr( real_pointer_t ptr ) SIXTRL_NOEXCEPT;

        /* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

        SIXTRL_FN const_real_pointer_t getY() const SIXTRL_NOEXCEPT;

        SIXTRL_FN real_pointer_t getY() SIXTRL_NOEXCEPT;

        SIXTRL_FN real_t getYValue(
            index_t const index ) const SIXTRL_NOEXCEPT;

        template< typename Iter >
        SIXTRL_FN void setY( Iter begin, Iter end ) SIXTRL_NOEXCEPT;

        SIXTRL_FN void setYValue(
            index_t const index, real_t const value ) SIXTRL_NOEXCEPT;

        SIXTRL_FN void assignYPtr( real_pointer_t ptr ) SIXTRL_NOEXCEPT;

        /* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

        SIXTRL_FN const_real_pointer_t getPx() const SIXTRL_NOEXCEPT;

        SIXTRL_FN real_pointer_t getPx() SIXTRL_NOEXCEPT;

        SIXTRL_FN real_t getPxValue(
            index_t const index ) const SIXTRL_NOEXCEPT;

        template< typename Iter >
        SIXTRL_FN void setPx( Iter begin, Iter end ) SIXTRL_NOEXCEPT;

        SIXTRL_FN void setPxValue(
            index_t const index, real_t const value ) SIXTRL_NOEXCEPT;

        SIXTRL_FN void assignPxPtr( real_pointer_t ptr ) SIXTRL_NOEXCEPT;

        /* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

        SIXTRL_FN const_real_pointer_t getPy() const SIXTRL_NOEXCEPT;

        SIXTRL_FN real_pointer_t getPy() SIXTRL_NOEXCEPT;

        SIXTRL_FN real_t getPyValue(
            index_t const index ) const SIXTRL_NOEXCEPT;

        template< typename Iter >
        SIXTRL_FN void setPy( Iter begin, Iter end ) SIXTRL_NOEXCEPT;

        SIXTRL_FN void setPyValue(
            index_t const index, real_t const value ) SIXTRL_NOEXCEPT;

        SIXTRL_FN void assignPyPtr( real_pointer_t ptr ) SIXTRL_NOEXCEPT;

        /* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

        SIXTRL_FN const_real_pointer_t getZeta() const SIXTRL_NOEXCEPT;

        SIXTRL_FN real_pointer_t getZeta() SIXTRL_NOEXCEPT;

        SIXTRL_FN real_t getZetaValue(
            index_t const index ) const SIXTRL_NOEXCEPT;

        template< typename Iter >
        SIXTRL_FN void setZeta( Iter begin, Iter end ) SIXTRL_NOEXCEPT;

        SIXTRL_FN void setZetaValue(
            index_t const index, real_t const value ) SIXTRL_NOEXCEPT;

        SIXTRL_FN void assignZetaPtr( real_pointer_t ptr ) SIXTRL_NOEXCEPT;

        /* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

        SIXTRL_FN const_real_pointer_t getPSigma() const SIXTRL_NOEXCEPT;

        SIXTRL_FN real_pointer_t getPSigma() SIXTRL_NOEXCEPT;

        SIXTRL_FN real_t getPSigmaValue(
            index_t const index ) const SIXTRL_NOEXCEPT;

        template< typename Iter >
        SIXTRL_FN void setPSigma( Iter begin, Iter end ) SIXTRL_NOEXCEPT;

        SIXTRL_FN void setPSigmaValue(
            index_t const index, real_t const value ) SIXTRL_NOEXCEPT;

        SIXTRL_FN void assignPSigmaPtr( real_pointer_t ptr ) SIXTRL_NOEXCEPT;

        /* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

        SIXTRL_FN const_real_pointer_t getDelta() const SIXTRL_NOEXCEPT;

        SIXTRL_FN real_pointer_t getDelta() SIXTRL_NOEXCEPT;

        SIXTRL_FN real_t getDeltaValue(
            index_t const index ) const SIXTRL_NOEXCEPT;

        template< typename Iter >
        SIXTRL_FN void setDelta( Iter begin, Iter end ) SIXTRL_NOEXCEPT;

        SIXTRL_FN void setDeltaValue(
            index_t const index, real_t const value ) SIXTRL_NOEXCEPT;

        SIXTRL_FN void assignDeltaPtr( real_pointer_t ptr ) SIXTRL_NOEXCEPT;

        /* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

        SIXTRL_FN const_real_pointer_t getRpp() const SIXTRL_NOEXCEPT;
        SIXTRL_FN real_pointer_t getRpp() SIXTRL_NOEXCEPT;
        SIXTRL_FN real_t getRppValue( index_t const index ) const SIXTRL_NOEXCEPT;

        template< typename Iter >
        SIXTRL_FN void setRpp( Iter begin, Iter end ) SIXTRL_NOEXCEPT;

        SIXTRL_FN void setRppValue(
            index_t const index, real_t const value ) SIXTRL_NOEXCEPT;

        SIXTRL_FN void assignRppPtr( real_pointer_t ptr ) SIXTRL_NOEXCEPT;

        /* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

        SIXTRL_FN const_real_pointer_t getRvv() const SIXTRL_NOEXCEPT;

        SIXTRL_FN real_pointer_t getRvv() SIXTRL_NOEXCEPT;

        SIXTRL_FN real_t getRvvValue(
            index_t const index ) const SIXTRL_NOEXCEPT;

        template< typename Iter >
        SIXTRL_FN void setRvv( Iter begin, Iter end ) SIXTRL_NOEXCEPT;

        SIXTRL_FN void setRvvValue(
            index_t const index, real_t const value ) SIXTRL_NOEXCEPT;

        SIXTRL_FN void assignRvvPtr( real_pointer_t ptr ) SIXTRL_NOEXCEPT;

        /* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

        SIXTRL_FN const_real_pointer_t getChi() const SIXTRL_NOEXCEPT;

        SIXTRL_FN real_pointer_t getChi() SIXTRL_NOEXCEPT;

        SIXTRL_FN real_t getChiValue(
            index_t const index ) const SIXTRL_NOEXCEPT;

        template< typename Iter >
        SIXTRL_FN void setChi( Iter begin, Iter end ) SIXTRL_NOEXCEPT;

        SIXTRL_FN void setChiValue(
            index_t const index, real_t const value ) SIXTRL_NOEXCEPT;

        SIXTRL_FN void assignChiPtr( real_pointer_t ptr ) SIXTRL_NOEXCEPT;

        /* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

        SIXTRL_FN const_index_pointer_t getParticleId() const SIXTRL_NOEXCEPT;
        SIXTRL_FN index_pointer_t getParticleId() SIXTRL_NOEXCEPT;

        SIXTRL_FN index_t getParticleIdValue(
            index_t const index ) const SIXTRL_NOEXCEPT;

        template< typename Iter >
        SIXTRL_FN void setParticleId( Iter begin, Iter end ) SIXTRL_NOEXCEPT;

        SIXTRL_FN void setParticleIdValue(
            index_t const index, index_t const value ) SIXTRL_NOEXCEPT;

        SIXTRL_FN void assignParticleIdPtr(
            index_pointer_t ptr ) SIXTRL_NOEXCEPT;

        /* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

        SIXTRL_FN const_index_pointer_t getAtElementId() const SIXTRL_NOEXCEPT;

        SIXTRL_FN index_pointer_t getAtElementId() SIXTRL_NOEXCEPT;

        SIXTRL_FN index_t getAtElementIdValue(
            index_t const index ) const SIXTRL_NOEXCEPT;

        template< typename Iter >
        SIXTRL_FN void setAtElementId( Iter begin, Iter end ) SIXTRL_NOEXCEPT;

        SIXTRL_FN void setAtElementIdValue(
            index_t const index, index_t const value ) SIXTRL_NOEXCEPT;

        SIXTRL_FN void assignAtElementIdPtr(
            index_pointer_t ptr ) SIXTRL_NOEXCEPT;

        /* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

        SIXTRL_FN const_index_pointer_t getAtTurn() const SIXTRL_NOEXCEPT;

        SIXTRL_FN index_pointer_t getAtTurn() SIXTRL_NOEXCEPT;

        SIXTRL_FN index_t getAtTurnValue(
            index_t const index ) const SIXTRL_NOEXCEPT;

        template< typename Iter >
        SIXTRL_FN void setAtTurn( Iter begin, Iter end ) SIXTRL_NOEXCEPT;

        SIXTRL_FN void setAtTurnValue(
            index_t const index, index_t const value ) SIXTRL_NOEXCEPT;

        SIXTRL_FN void assignAtTurnPtr( index_pointer_t ptr ) SIXTRL_NOEXCEPT;

        /* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

        SIXTRL_FN const_index_pointer_t getState() const SIXTRL_NOEXCEPT;
        SIXTRL_FN index_pointer_t getState() SIXTRL_NOEXCEPT;

        SIXTRL_FN index_t getStateValue(
            index_t const index ) const SIXTRL_NOEXCEPT;

        template< typename Iter >
        SIXTRL_FN void setState( Iter begin, Iter end ) SIXTRL_NOEXCEPT;

        SIXTRL_FN void setStateValue(
            index_t const index, index_t const value ) SIXTRL_NOEXCEPT;

        SIXTRL_FN void assignStatePtr( index_pointer_t ptr ) SIXTRL_NOEXCEPT;

        /* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

        SIXTRL_FN real_t realValueGetterFn(
            const_real_pointer_t SIXTRL_RESTRICT ptr,
            index_t const index ) SIXTRL_NOEXCEPT;

        SIXTRL_FN index_t indexValueGetterFn(
            const_index_pointer_t SIXTRL_RESTRICT ptr,
            index_t const index ) SIXTRL_NOEXCEPT;

        template< typename V, typename Ptr >
        SIXTRL_FN void valueSetterFn( Ptr* SIXTRL_RESTRICT ptr,
                            index_t const index,
                            V const value ) SIXTRL_NOEXCEPT;

        /* ----------------------------------------------------------------- */

        num_elements_t  num_of_particles SIXTRL_ALIGN( 8 );
        real_pointer_t  q0               SIXTRL_ALIGN( 8 );
        real_pointer_t  mass0            SIXTRL_ALIGN( 8 );
        real_pointer_t  beta0            SIXTRL_ALIGN( 8 );
        real_pointer_t  gamma0           SIXTRL_ALIGN( 8 );
        real_pointer_t  p0c              SIXTRL_ALIGN( 8 );
        real_pointer_t  s                SIXTRL_ALIGN( 8 );
        real_pointer_t  x                SIXTRL_ALIGN( 8 );
        real_pointer_t  y                SIXTRL_ALIGN( 8 );
        real_pointer_t  px               SIXTRL_ALIGN( 8 );
        real_pointer_t  py               SIXTRL_ALIGN( 8 );
        real_pointer_t  zeta             SIXTRL_ALIGN( 8 );
        real_pointer_t  psigma           SIXTRL_ALIGN( 8 );
        real_pointer_t  delta            SIXTRL_ALIGN( 8 );
        real_pointer_t  rpp              SIXTRL_ALIGN( 8 );
        real_pointer_t  rvv              SIXTRL_ALIGN( 8 );
        real_pointer_t  chi              SIXTRL_ALIGN( 8 );
        index_pointer_t particle_id      SIXTRL_ALIGN( 8 );
        index_pointer_t at_element_id    SIXTRL_ALIGN( 8 );
        index_pointer_t at_turn          SIXTRL_ALIGN( 8 );
        index_pointer_t state            SIXTRL_ALIGN( 8 );
    };

    /* ===================================================================== */
    /* Specialization for T = SIXTRL_REAL_T: */
    /* ===================================================================== */

    template<> struct TParticles< NS(particle_real_t) > :
        public ::NS(Particles)
    {
        using num_elements_t = NS(particle_num_elements_t);

        using real_t = typename std::iterator_traits<
            NS(particle_real_ptr_t) >::value_type;

        using real_pointer_t        = real_t*;
        using const_real_pointer_t  = real_t const*;

        using index_t = typename std::iterator_traits<
            NS(particle_index_ptr_t) >::value_type;

        using index_pointer_t       = index_t*;
        using const_index_pointer_t = index_t const*;

        using type_id_t             = NS(object_type_id_t);
        using size_type             = NS(buffer_size_t);
        using buffer_t   	        = ::NS(Buffer);
        using c_api_t               = ::NS(Particles);

        SIXTRL_FN TParticles() = default;

        SIXTRL_FN TParticles(
            TParticles< NS(particle_real_t) > const& other ) = default;

        SIXTRL_FN TParticles(
            TParticles< NS(particle_real_t) >&& other ) = default;

        SIXTRL_FN TParticles< NS(particle_real_t) >& operator=(
            TParticles< NS(particle_real_t) > const& rhs ) = default;

        SIXTRL_FN TParticles< NS(particle_real_t) >& operator=(
            TParticles< NS(particle_real_t) >&& rhs ) = default;

        SIXTRL_FN ~TParticles() = default;

        SIXTRL_FN type_id_t getTypeId() const SIXTRL_NOEXCEPT;

        /* ----------------------------------------------------------------- */

        SIXTRL_FN static bool CanAddToBuffer(
            buffer_t& SIXTRL_RESTRICT_REF buffer,
            size_type const num_particles,
            size_type* SIXTRL_RESTRICT ptr_requ_objects = nullptr,
            size_type* SIXTRL_RESTRICT ptr_requ_slots = nullptr,
            size_type* SIXTRL_RESTRICT ptr_requ_dataptrs = nullptr
            ) SIXTRL_NOEXCEPT;

        SIXTRL_FN SIXTRL_STATIC TParticles< NS(particle_real_t) >*
        CreateNewOnBuffer( buffer_t& SIXTRL_RESTRICT_REF buffer,
            size_type const num_particles );

        SIXTRL_FN SIXTRL_STATIC TParticles< NS(particle_real_t) >* AddToBuffer(
            buffer_t& SIXTRL_RESTRICT_REF buffer,
            size_type const num_particles,
            real_pointer_t  q0_ptr            = nullptr,
            real_pointer_t  mass0_ptr         = nullptr,
            real_pointer_t  beta0_ptr         = nullptr,
            real_pointer_t  gamma0_ptr        = nullptr,
            real_pointer_t  p0c_ptr           = nullptr,
            real_pointer_t  s_ptr             = nullptr,
            real_pointer_t  x_ptr             = nullptr,
            real_pointer_t  y_ptr             = nullptr,
            real_pointer_t  px_ptr            = nullptr,
            real_pointer_t  py_ptr            = nullptr,
            real_pointer_t  zeta_ptr          = nullptr,
            real_pointer_t  psigma_ptr        = nullptr,
            real_pointer_t  delta_ptr         = nullptr,
            real_pointer_t  rpp_ptr           = nullptr,
            real_pointer_t  rvv_ptr           = nullptr,
            real_pointer_t  chi_ptr           = nullptr,
            index_pointer_t particle_id_ptr   = nullptr,
            index_pointer_t at_element_id_ptr = nullptr,
            index_pointer_t at_turn_ptr       = nullptr,
            index_pointer_t state_ptr         = nullptr );

        /* ----------------------------------------------------------------- */

        SIXTRL_FN bool copy( TParticles< NS(particle_real_t) > const&
            SIXTRL_RESTRICT_REF other ) SIXTRL_NOEXCEPT;

        SIXTRL_FN bool copy( SIXTRL_PARTICLE_ARGPTR_DEC NS(Particles) const*
                SIXTRL_RESTRICT other ) SIXTRL_NOEXCEPT;

        SIXTRL_FN bool copySingle( SIXTRL_PARTICLE_ARGPTR_DEC
            TParticles< NS(particle_real_t) > const& SIXTRL_RESTRICT_REF other,
            index_t const source_index,
            index_t dest_index = index_t{ -1 } ) SIXTRL_NOEXCEPT;

        SIXTRL_FN bool copySingle( SIXTRL_PARTICLE_ARGPTR_DEC
            NS(Particles) const* SIXTRL_RESTRICT other,
            index_t const source_index,
            index_t dest_index = index_t{ -1 } ) SIXTRL_NOEXCEPT;

        SIXTRL_FN bool copyRange(
            TParticles< NS(particle_real_t) > const& SIXTRL_RESTRICT_REF other,
            index_t const src_start_idx,
            index_t const src_end_idx,
            index_t dst_start_idx = index_t{ -1 } ) SIXTRL_NOEXCEPT;

        SIXTRL_FN bool copyRange( SIXTRL_PARTICLE_ARGPTR_DEC NS(Particles)
            const* SIXTRL_RESTRICT other,
            index_t const src_start_idx,
            index_t const src_end_idx,
            index_t dst_start_idx = index_t{ -1 } ) SIXTRL_NOEXCEPT;

        /* ----------------------------------------------------------------- */

        static SIXTRL_BUFFER_OBJ_DATAPTR_DEC TParticles< NS(particle_real_t) > const*
        FromBuffer( Buffer const& SIXTRL_RESTRICT_REF buffer,
                    Buffer::size_type const particle_obj_index ) SIXTRL_NOEXCEPT;

        static SIXTRL_BUFFER_OBJ_DATAPTR_DEC TParticles< NS(particle_real_t) > const*
        FromBuffer( SIXTRL_BUFFER_ARGPTR_DEC const NS(Buffer) *const
            SIXTRL_RESTRICT buffer,
            NS(buffer_size_t) const particle_obj_index ) SIXTRL_NOEXCEPT;

        static SIXTRL_BUFFER_OBJ_DATAPTR_DEC TParticles< NS(particle_real_t) >*
        FromBuffer( Buffer& SIXTRL_RESTRICT_REF buffer,
                    Buffer::size_type const particle_obj_index ) SIXTRL_NOEXCEPT;

        static SIXTRL_BUFFER_OBJ_DATAPTR_DEC TParticles< NS(particle_real_t) >*
        FromBuffer( SIXTRL_BUFFER_ARGPTR_DEC NS(Buffer)*const SIXTRL_RESTRICT buffer,
            NS(buffer_size_t) const particle_obj_index ) SIXTRL_NOEXCEPT;

        /* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

        static SIXTRL_BUFFER_OBJ_DATAPTR_DEC TParticles< NS(particle_real_t) > const*
        FromBufferObject( SIXTRL_BUFFER_OBJ_ARGPTR_DEC const NS(Object) *const
            SIXTRL_RESTRICT index_obj ) SIXTRL_NOEXCEPT;

        static SIXTRL_BUFFER_OBJ_DATAPTR_DEC TParticles< NS(particle_real_t) >*
        FromBufferObject( SIXTRL_BUFFER_OBJ_ARGPTR_DEC NS(Object)*
            SIXTRL_RESTRICT index_obj ) SIXTRL_NOEXCEPT;

        /* ----------------------------------------------------------------- */

        SIXTRL_FN c_api_t const* getCApiPtr() const SIXTRL_NOEXCEPT;
        SIXTRL_FN c_api_t* getCApiPtr() SIXTRL_NOEXCEPT;

        /* ----------------------------------------------------------------- */

        SIXTRL_FN num_elements_t getNumParticles() const SIXTRL_NOEXCEPT;
        SIXTRL_FN void setNumParticles(
            size_type const num_particles ) SIXTRL_NOEXCEPT;

        SIXTRL_FN void preset() SIXTRL_NOEXCEPT;

        /* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

        SIXTRL_FN const_real_pointer_t getQ0() const SIXTRL_NOEXCEPT;
        SIXTRL_FN real_pointer_t getQ0() SIXTRL_NOEXCEPT;

        SIXTRL_FN real_t getQ0Value(
            index_t const index ) const SIXTRL_NOEXCEPT;

        template< typename Iter >
        SIXTRL_FN void setQ0( Iter begin, Iter end ) SIXTRL_NOEXCEPT;

        SIXTRL_FN void setQ0Value(
            index_t const index, real_t const value ) SIXTRL_NOEXCEPT;

        SIXTRL_FN void assignQ0Ptr( real_pointer_t ptr ) SIXTRL_NOEXCEPT;

        /* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

        SIXTRL_FN const_real_pointer_t getMass0() const SIXTRL_NOEXCEPT;
        SIXTRL_FN real_pointer_t getMass0() SIXTRL_NOEXCEPT;

        SIXTRL_FN real_t getMass0Value(
            index_t const index ) const SIXTRL_NOEXCEPT;

        template< typename Iter >
        SIXTRL_FN void setMass0( Iter begin, Iter end ) SIXTRL_NOEXCEPT;

        SIXTRL_FN void setMass0Value(
            index_t const index, real_t const value ) SIXTRL_NOEXCEPT;

        SIXTRL_FN void assignMass0Ptr( real_pointer_t ptr ) SIXTRL_NOEXCEPT;

        /* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

        SIXTRL_FN const_real_pointer_t getBeta0() const SIXTRL_NOEXCEPT;
        SIXTRL_FN real_pointer_t getBeta0() SIXTRL_NOEXCEPT;

        SIXTRL_FN real_t getBeta0Value(
            index_t const index ) const SIXTRL_NOEXCEPT;

        template< typename Iter >
        SIXTRL_FN void setBeta0( Iter begin, Iter end ) SIXTRL_NOEXCEPT;

        SIXTRL_FN void setBeta0Value(
            index_t const index, real_t const value ) SIXTRL_NOEXCEPT;

        SIXTRL_FN void assignBeta0Ptr( real_pointer_t ptr ) SIXTRL_NOEXCEPT;

        /* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

        SIXTRL_FN const_real_pointer_t getGamma0() const SIXTRL_NOEXCEPT;
        SIXTRL_FN real_pointer_t getGamma0() SIXTRL_NOEXCEPT;

        SIXTRL_FN real_t getGamma0Value(
            index_t const index ) const SIXTRL_NOEXCEPT;

        template< typename Iter >
        SIXTRL_FN void setGamma0( Iter begin, Iter end ) SIXTRL_NOEXCEPT;

        SIXTRL_FN void setGamma0Value(
            index_t const index, real_t const value ) SIXTRL_NOEXCEPT;

        SIXTRL_FN void assignGamma0Ptr( real_pointer_t ptr ) SIXTRL_NOEXCEPT;

        /* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

        SIXTRL_FN const_real_pointer_t getP0c() const SIXTRL_NOEXCEPT;
        SIXTRL_FN real_pointer_t getP0c() SIXTRL_NOEXCEPT;

        SIXTRL_FN real_t getP0cValue(
            index_t const index ) const SIXTRL_NOEXCEPT;

        template< typename Iter >
        SIXTRL_FN void setP0c( Iter begin, Iter end ) SIXTRL_NOEXCEPT;

        SIXTRL_FN void setP0cValue(
            index_t const index, real_t const value ) SIXTRL_NOEXCEPT;

        SIXTRL_FN void assignP0cPtr( real_pointer_t ptr ) SIXTRL_NOEXCEPT;

        /* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

        SIXTRL_FN const_real_pointer_t getS() const SIXTRL_NOEXCEPT;
        SIXTRL_FN real_pointer_t getS() SIXTRL_NOEXCEPT;

        SIXTRL_FN real_t getSValue(
            index_t const index ) const SIXTRL_NOEXCEPT;

        template< typename Iter >
        SIXTRL_FN void setS( Iter begin, Iter end ) SIXTRL_NOEXCEPT;

        SIXTRL_FN void setSValue(
            index_t const index, real_t const value ) SIXTRL_NOEXCEPT;

        SIXTRL_FN void assignSPtr( real_pointer_t ptr ) SIXTRL_NOEXCEPT;

        /* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

        SIXTRL_FN const_real_pointer_t getX() const SIXTRL_NOEXCEPT;
        SIXTRL_FN real_pointer_t getX() SIXTRL_NOEXCEPT;

        SIXTRL_FN real_t getXValue(
            index_t const index ) const SIXTRL_NOEXCEPT;

        template< typename Iter >
        SIXTRL_FN void setX( Iter begin, Iter end ) SIXTRL_NOEXCEPT;

        SIXTRL_FN void setXValue(
            index_t const index, real_t const value ) SIXTRL_NOEXCEPT;

        SIXTRL_FN void assignXPtr( real_pointer_t ptr ) SIXTRL_NOEXCEPT;

        /* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

        SIXTRL_FN const_real_pointer_t getY() const SIXTRL_NOEXCEPT;
        SIXTRL_FN real_pointer_t getY() SIXTRL_NOEXCEPT;

        SIXTRL_FN real_t getYValue(
            index_t const index ) const SIXTRL_NOEXCEPT;

        template< typename Iter >
        SIXTRL_FN void setY( Iter begin, Iter end ) SIXTRL_NOEXCEPT;

        SIXTRL_FN void setYValue(
            index_t const index, real_t const value ) SIXTRL_NOEXCEPT;

        SIXTRL_FN void assignYPtr( real_pointer_t ptr ) SIXTRL_NOEXCEPT;

        /* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

        SIXTRL_FN const_real_pointer_t getPx() const SIXTRL_NOEXCEPT;
        SIXTRL_FN real_pointer_t getPx() SIXTRL_NOEXCEPT;

        SIXTRL_FN real_t getPxValue(
            index_t const index ) const SIXTRL_NOEXCEPT;

        template< typename Iter >
        SIXTRL_FN void setPx( Iter begin, Iter end ) SIXTRL_NOEXCEPT;

        SIXTRL_FN void setPxValue(
            index_t const index, real_t const value ) SIXTRL_NOEXCEPT;

        SIXTRL_FN void assignPxPtr( real_pointer_t ptr ) SIXTRL_NOEXCEPT;

        /* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

        SIXTRL_FN const_real_pointer_t getPy() const SIXTRL_NOEXCEPT;
        SIXTRL_FN real_pointer_t getPy() SIXTRL_NOEXCEPT;

        SIXTRL_FN real_t getPyValue(
            index_t const index ) const SIXTRL_NOEXCEPT;

        template< typename Iter >
        SIXTRL_FN void setPy( Iter begin, Iter end ) SIXTRL_NOEXCEPT;

        SIXTRL_FN void setPyValue(
            index_t const index, real_t const value ) SIXTRL_NOEXCEPT;

        SIXTRL_FN void assignPyPtr( real_pointer_t ptr ) SIXTRL_NOEXCEPT;

        /* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

        SIXTRL_FN const_real_pointer_t getZeta() const SIXTRL_NOEXCEPT;
        SIXTRL_FN real_pointer_t getZeta() SIXTRL_NOEXCEPT;

        SIXTRL_FN real_t getZetaValue(
            index_t const index ) const SIXTRL_NOEXCEPT;

        template< typename Iter >
        SIXTRL_FN void setZeta( Iter begin, Iter end ) SIXTRL_NOEXCEPT;

        SIXTRL_FN void setZetaValue(
            index_t const index, real_t const value ) SIXTRL_NOEXCEPT;

        SIXTRL_FN void assignZetaPtr( real_pointer_t ptr ) SIXTRL_NOEXCEPT;

        /* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

        SIXTRL_FN const_real_pointer_t getPSigma() const SIXTRL_NOEXCEPT;
        SIXTRL_FN real_pointer_t getPSigma() SIXTRL_NOEXCEPT;

        SIXTRL_FN real_t getPSigmaValue(
            index_t const index ) const SIXTRL_NOEXCEPT;

        template< typename Iter >
        SIXTRL_FN void setPSigma( Iter begin, Iter end ) SIXTRL_NOEXCEPT;

        SIXTRL_FN void setPSigmaValue(
            index_t const index, real_t const value ) SIXTRL_NOEXCEPT;

        SIXTRL_FN void assignPSigmaPtr( real_pointer_t ptr ) SIXTRL_NOEXCEPT;

        /* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

        SIXTRL_FN const_real_pointer_t getDelta() const SIXTRL_NOEXCEPT;
        SIXTRL_FN real_pointer_t getDelta() SIXTRL_NOEXCEPT;

        SIXTRL_FN real_t getDeltaValue(
            index_t const index ) const SIXTRL_NOEXCEPT;

        template< typename Iter >
        SIXTRL_FN void setDelta( Iter begin, Iter end ) SIXTRL_NOEXCEPT;

        SIXTRL_FN void setDeltaValue(
            index_t const index, real_t const value ) SIXTRL_NOEXCEPT;

        SIXTRL_FN void assignDeltaPtr( real_pointer_t ptr ) SIXTRL_NOEXCEPT;

        /* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

        SIXTRL_FN const_real_pointer_t getRpp() const SIXTRL_NOEXCEPT;
        SIXTRL_FN real_pointer_t getRpp() SIXTRL_NOEXCEPT;

        SIXTRL_FN real_t getRppValue(
            index_t const index ) const SIXTRL_NOEXCEPT;

        template< typename Iter >
        SIXTRL_FN void setRpp( Iter begin, Iter end ) SIXTRL_NOEXCEPT;

        SIXTRL_FN void setRppValue(
            index_t const index, real_t const value ) SIXTRL_NOEXCEPT;

        SIXTRL_FN void assignRppPtr( real_pointer_t ptr ) SIXTRL_NOEXCEPT;

        /* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

        SIXTRL_FN const_real_pointer_t getRvv() const SIXTRL_NOEXCEPT;
        SIXTRL_FN real_pointer_t getRvv() SIXTRL_NOEXCEPT;

        SIXTRL_FN real_t getRvvValue(
            index_t const index ) const SIXTRL_NOEXCEPT;

        template< typename Iter >
        SIXTRL_FN void setRvv( Iter begin, Iter end ) SIXTRL_NOEXCEPT;

        SIXTRL_FN void setRvvValue(
            index_t const index, real_t const value ) SIXTRL_NOEXCEPT;

        SIXTRL_FN void assignRvvPtr( real_pointer_t ptr ) SIXTRL_NOEXCEPT;

        /* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

        SIXTRL_FN const_real_pointer_t getChi() const SIXTRL_NOEXCEPT;
        SIXTRL_FN real_pointer_t getChi() SIXTRL_NOEXCEPT;

        SIXTRL_FN real_t getChiValue(
            index_t const index ) const SIXTRL_NOEXCEPT;

        template< typename Iter >
        SIXTRL_FN void setChi( Iter begin, Iter end ) SIXTRL_NOEXCEPT;

        SIXTRL_FN void setChiValue(
            index_t const index, real_t const value ) SIXTRL_NOEXCEPT;

        SIXTRL_FN void assignChiPtr( real_pointer_t ptr ) SIXTRL_NOEXCEPT;

        /* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

        SIXTRL_FN const_index_pointer_t getParticleId() const SIXTRL_NOEXCEPT;
        SIXTRL_FN index_pointer_t getParticleId() SIXTRL_NOEXCEPT;

        SIXTRL_FN index_t getParticleIdValue(
            index_t const index ) const SIXTRL_NOEXCEPT;

        template< typename Iter >
        SIXTRL_FN void setParticleId( Iter begin, Iter end ) SIXTRL_NOEXCEPT;

        SIXTRL_FN void setParticleIdValue(
            index_t const index, index_t const value ) SIXTRL_NOEXCEPT;

        SIXTRL_FN void assignParticleIdPtr(
            index_pointer_t ptr ) SIXTRL_NOEXCEPT;

        /* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

        SIXTRL_FN const_index_pointer_t getAtElementId() const SIXTRL_NOEXCEPT;
        SIXTRL_FN index_pointer_t getAtElementId() SIXTRL_NOEXCEPT;

        SIXTRL_FN index_t getAtElementIdValue(
            index_t const index ) const SIXTRL_NOEXCEPT;

        template< typename Iter >
        SIXTRL_FN void setAtElementId( Iter begin, Iter end ) SIXTRL_NOEXCEPT;

        SIXTRL_FN void setAtElementIdValue(
            index_t const index, index_t const value ) SIXTRL_NOEXCEPT;

        SIXTRL_FN void assignAtElementIdPtr(
            index_pointer_t ptr ) SIXTRL_NOEXCEPT;

        /* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

        SIXTRL_FN const_index_pointer_t getAtTurn() const SIXTRL_NOEXCEPT;
        SIXTRL_FN index_pointer_t getAtTurn() SIXTRL_NOEXCEPT;

        SIXTRL_FN index_t getAtTurnValue(
            index_t const index ) const SIXTRL_NOEXCEPT;

        template< typename Iter >
        SIXTRL_FN void setAtTurn( Iter begin, Iter end ) SIXTRL_NOEXCEPT;

        SIXTRL_FN void setAtTurnValue(
            index_t const index, index_t const value ) SIXTRL_NOEXCEPT;

        SIXTRL_FN void assignAtTurnPtr(
            index_pointer_t ptr ) SIXTRL_NOEXCEPT;

        /* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

        SIXTRL_FN const_index_pointer_t getState() const SIXTRL_NOEXCEPT;
        SIXTRL_FN index_pointer_t getState() SIXTRL_NOEXCEPT;

        SIXTRL_FN index_t getStateValue(
            index_t const index ) const SIXTRL_NOEXCEPT;

        template< typename Iter >
        SIXTRL_FN void setState( Iter begin, Iter end ) SIXTRL_NOEXCEPT;

        SIXTRL_FN void setStateValue(
            index_t const index, index_t const value ) SIXTRL_NOEXCEPT;

        SIXTRL_FN void assignStatePtr(
            index_pointer_t ptr ) SIXTRL_NOEXCEPT;

        /* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */
    };

    using Particles = TParticles< NS(particle_real_t) >;

    SIXTRL_FN SIXTRL_STATIC bool Buffer_is_particles_buffer(
        Buffer const& SIXTRL_RESTRICT_REF buffer );

    SIXTRL_FN SIXTRL_STATIC Particles::size_type
    Particles_buffer_get_total_num_of_particles(
        Buffer const& SIXTRL_RESTRICT_REF buffer );

    SIXTRL_FN SIXTRL_STATIC Buffer::size_type
    Particles_buffer_get_num_of_particle_blocks(
        Buffer const& SIXTRL_RESTRICT_REF buffer );
}

/* ************************************************************************* *
 * *** Implementation of inline and template member functions          ***** *
 * ************************************************************************* */

namespace SIXTRL_CXX_NAMESPACE
{
    /* ===================================================================== */
    /* TParticles< T >: */
    /* ===================================================================== */

    template< typename T >
    SIXTRL_INLINE typename TParticles< T >::type_id_t
    TParticles< T >::getTypeId() const SIXTRL_NOEXCEPT
    {
        return NS(OBJECT_TYPE_PARTICLE);
    }

    /* ----------------------------------------------------------------- */

    template< typename T >
    SIXTRL_INLINE bool TParticles< T >::copy(
        TParticles< T > const& other ) SIXTRL_NOEXCEPT
    {
        using index_t = typename TParticles< T >::index_t;

        return this->copyRange(
            other, index_t{ 0 }, other.getNumParticles(), index_t{ 0 } );
    }

    template< typename T >
    SIXTRL_INLINE bool TParticles< T >::copyRange(
        TParticles< T > const& other,
        typename TParticles< T >::index_t const src_start_idx,
        typename TParticles< T >::index_t const src_end_idx,
        typename TParticles< T >::index_t dst_start_idx ) SIXTRL_NOEXCEPT
    {
        using num_elem_t = typename TParticles< T >::num_elements_t;
        using index_t    = typename TParticles< T >::index_t;

        bool success = false;

        num_elem_t const num_to_copy = ( src_start_idx <= src_end_idx )
            ? ( src_end_idx - src_start_idx ) : num_elem_t{ 0 };

        num_elem_t const source_num_particles = other.getNumParticles();
        num_elem_t const dest_num_particles   = this->getNumParticles();

        if( ( dst_start_idx < num_elem_t{ 0 } ) ||
            ( dst_start_idx >= dest_num_particles ) )
        {
            if( src_end_idx < dest_num_particles )
            {
                dst_start_idx = src_start_idx;
            }
        }

        if( ( &other != this ) &&
            ( src_start_idx >= index_t{ 0 } ) &&
            ( src_end_idx >= src_start_idx ) &&
            ( source_num_particles >= src_end_idx ) &&
            ( dst_start_idx >= index_t{ 0 } ) &&
            ( dest_num_particles >= ( dst_start_idx + num_to_copy ) ) )
        {
            success = true;

            SIXTRL_ASSERT( other.q0             != nullptr );
            SIXTRL_ASSERT( other.beta0          != nullptr );
            SIXTRL_ASSERT( other.mass0          != nullptr );
            SIXTRL_ASSERT( other.gamma0         != nullptr );
            SIXTRL_ASSERT( other.p0c            != nullptr );
            SIXTRL_ASSERT( other.s              != nullptr );
            SIXTRL_ASSERT( other.x              != nullptr );
            SIXTRL_ASSERT( other.y              != nullptr );
            SIXTRL_ASSERT( other.px             != nullptr );
            SIXTRL_ASSERT( other.py             != nullptr );
            SIXTRL_ASSERT( other.zeta           != nullptr );
            SIXTRL_ASSERT( other.psigma         != nullptr );
            SIXTRL_ASSERT( other.delta          != nullptr );
            SIXTRL_ASSERT( other.rpp            != nullptr );
            SIXTRL_ASSERT( other.rvv            != nullptr );
            SIXTRL_ASSERT( other.chi            != nullptr );
            SIXTRL_ASSERT( other.particle_id    != nullptr );
            SIXTRL_ASSERT( other.at_element_id  != nullptr );
            SIXTRL_ASSERT( other.at_turn        != nullptr );
            SIXTRL_ASSERT( other.state          != nullptr );

            SIXTRL_ASSERT( this->q0             != nullptr );
            SIXTRL_ASSERT( this->beta0          != nullptr );
            SIXTRL_ASSERT( this->mass0          != nullptr );
            SIXTRL_ASSERT( this->gamma0         != nullptr );
            SIXTRL_ASSERT( this->p0c            != nullptr );
            SIXTRL_ASSERT( this->s              != nullptr );
            SIXTRL_ASSERT( this->x              != nullptr );
            SIXTRL_ASSERT( this->y              != nullptr );
            SIXTRL_ASSERT( this->px             != nullptr );
            SIXTRL_ASSERT( this->py             != nullptr );
            SIXTRL_ASSERT( this->zeta           != nullptr );
            SIXTRL_ASSERT( this->psigma         != nullptr );
            SIXTRL_ASSERT( this->delta          != nullptr );
            SIXTRL_ASSERT( this->rpp            != nullptr );
            SIXTRL_ASSERT( this->rvv            != nullptr );
            SIXTRL_ASSERT( this->chi            != nullptr );
            SIXTRL_ASSERT( this->particle_id    != nullptr );
            SIXTRL_ASSERT( this->at_element_id  != nullptr );
            SIXTRL_ASSERT( this->at_turn        != nullptr );
            SIXTRL_ASSERT( this->state          != nullptr );

            std::copy( &other.q0[ src_start_idx ],
                &other.q0[ src_end_idx ], &this->q0[ dst_start_idx ] );

            std::copy( &other.mass0[ src_start_idx ],
                &other.mass0[ src_end_idx ], &this->mass0[ dst_start_idx ] );

            std::copy( &other.beta0[ src_start_idx ],
                &other.beta0[ src_end_idx ], &this->beta0[ dst_start_idx ] );

            std::copy( &other.gamma0[ src_start_idx ],
                &other.gamma0[ src_end_idx ], &this->gamma0[ dst_start_idx ] );

            std::copy( &other.p0c[ src_start_idx ],
                &other.p0c[ src_end_idx ], &this->p0c[ dst_start_idx ] );

            std::copy( &other.s[ src_start_idx ],
                &other.s[ src_end_idx ], &this->s[ dst_start_idx ] );

            std::copy( &other.x[ src_start_idx ],
                &other.x[ src_end_idx ], &this->x[ dst_start_idx ] );

            std::copy( &other.y[ src_start_idx ],
                &other.y[ src_end_idx ], &this->y[ dst_start_idx ] );

            std::copy( &other.px[ src_start_idx ],
                &other.px[ src_end_idx ], &this->px[ dst_start_idx ] );

            std::copy( &other.py[ src_start_idx ],
                &other.py[ src_end_idx ], &this->py[ dst_start_idx ] );

            std::copy( &other.zeta[ src_start_idx ],
                &other.zeta[ src_end_idx ], &this->zeta[ dst_start_idx ] );

            std::copy( &other.psigma[ src_start_idx ],
                &other.psigma[ src_end_idx ], &this->psigma[ dst_start_idx ] );

            std::copy( &other.delta[ src_start_idx ],
                &other.delta[ src_end_idx ], &this->delta[ dst_start_idx ] );

            std::copy( &other.rpp[ src_start_idx ],
                &other.rpp[ src_end_idx ], &this->rpp[ dst_start_idx ] );

            std::copy( &other.rvv[ src_start_idx ],
                &other.rvv[ src_end_idx ], &this->rvv[ dst_start_idx ] );

            std::copy( &other.chi[ src_start_idx ],
                &other.chi[ src_end_idx ], &this->chi[ dst_start_idx ] );

            std::copy( &other.particle_id[ src_start_idx ],
                       &other.particle_id[ src_end_idx ],
                       &this->particle_id[ dst_start_idx ] );

            std::copy( &other.at_element_id[ src_start_idx ],
                       &other.at_element_id[ src_end_idx ],
                       &this->at_element_id[ dst_start_idx ] );

            std::copy( &other.at_turn[ src_start_idx ],
                       &other.at_turn[ src_end_idx ],
                       &this->at_turn[ dst_start_idx ] );

            std::copy( &other.state[ src_start_idx ],
                       &other.state[ src_end_idx ],
                       &this->state[ dst_start_idx ] );

            success = true;
        }

        return success;
    }

    template< typename T >
    SIXTRL_INLINE bool TParticles< T >::copySingle(
        TParticles< T > const& other,
        typename TParticles< T >::index_t const src_idx,
        typename TParticles< T >::index_t dst_idx ) SIXTRL_NOEXCEPT
    {
        using num_elem_t = typename TParticles< T >::num_elements_t;
        using index_t    = typename TParticles< T >::index_t;

        bool success = false;

        num_elem_t const src_num_particles = other.getNumParticles();
        num_elem_t const dst_num_particles = this->getNumParticles();

        if( ( dst_idx < num_elem_t{ 0 } ) || ( dst_idx >= dst_num_particles ) )
        {
            if( src_idx < dst_num_particles )
            {
                dst_idx = src_idx;
            }
        }

        if( ( &other != this ) &&
            ( src_idx >= index_t{ 0 } ) && ( src_idx <  src_num_particles ) &&
            ( dst_idx >= index_t{ 0 } ) && ( dst_idx <  dst_num_particles ) )
        {
            this->setQ0Value(     dst_idx, other.getQ0Value(     src_idx ) );
            this->setMass0Value(  dst_idx, other.getMass0Value(  src_idx ) );
            this->setBeta0Value(  dst_idx, other.getBeta0Value(  src_idx ) );
            this->setGamma0Value( dst_idx, other.getGamma0Value( src_idx ) );
            this->setP0cValue(    dst_idx, other.getP0cValue(    src_idx ) );

            this->setSValue(      dst_idx, other.getSValue(      src_idx ) );
            this->setXValue(      dst_idx, other.getXValue(      src_idx ) );
            this->setYValue(      dst_idx, other.getYValue(      src_idx ) );
            this->setPxValue(     dst_idx, other.getPxValue(     src_idx ) );
            this->setPyValue(     dst_idx, other.getPyValue(     src_idx ) );
            this->setZetaValue(   dst_idx, other.getZetaValue(   src_idx ) );

            this->setPSigmaValue( dst_idx, other.getPSigmaValue( src_idx ) );
            this->setDeltaValue(  dst_idx, other.getDeltaValue(  src_idx ) );
            this->setRppValue(    dst_idx, other.getRppValue(    src_idx ) );
            this->setRvvValue(    dst_idx, other.getRvvValue(    src_idx ) );
            this->setChiValue(    dst_idx, other.getChiValue(    src_idx ) );

            this->setParticleIdValue(  dst_idx,
                                       other.getParticleIdValue( src_idx ) );

            this->setAtElementIdValue( dst_idx,
                                       other.getAtElementIdValue( src_idx ) );

            this->setAtTurnValue( dst_idx,  other.getAtTurnValue( src_idx ) );
            this->setStateValue(  dst_idx,  other.getStateValue(  src_idx ) );

            success = true;
        }

        return success;
    }

    /* ----------------------------------------------------------------- */

    template< typename T >
    SIXTRL_INLINE  bool TParticles< T >::CanAddToBuffer(
        typename TParticles< T >::buffer_t& SIXTRL_RESTRICT_REF buffer,
        typename TParticles< T >::size_type const num_particles,
        typename TParticles< T >::size_type* SIXTRL_RESTRICT ptr_requ_objects,
        typename TParticles< T >::size_type* SIXTRL_RESTRICT ptr_requ_slots,
        typename TParticles< T >::size_type* SIXTRL_RESTRICT ptr_requ_dataptrs
        ) SIXTRL_NOEXCEPT
    {
        using _this_t = TParticles< T >;

        static_assert( std::is_trivial< _this_t >::value, "" );
        static_assert( std::is_standard_layout< _this_t >::value, "" );

        using size_t  = typename _this_t::size_type;

        size_t const real_size    = sizeof( real_t );
        size_t const index_size   = sizeof( index_t );
        size_t const num_dataptrs = NS(PARTICLES_NUM_DATAPTRS);

        size_t const sizes[] =
        {
            real_size,  real_size,  real_size,  real_size,
            real_size,  real_size,  real_size,  real_size,
            real_size,  real_size,  real_size,  real_size,
            real_size,  real_size,  real_size,  real_size,
            index_size, index_size, index_size, index_size
        };

        size_t const counts[] =
        {
            num_particles, num_particles, num_particles, num_particles,
            num_particles, num_particles, num_particles, num_particles,
            num_particles, num_particles, num_particles, num_particles,
            num_particles, num_particles, num_particles, num_particles,
            num_particles, num_particles, num_particles, num_particles
        };

        return ::NS(Buffer_can_add_object)( &buffer, sizeof( _this_t ),
            num_dataptrs, sizes, counts, ptr_requ_objects, ptr_requ_slots,
                ptr_requ_dataptrs );
    }

    template< typename T >
    SIXTRL_INLINE  TParticles< T >* TParticles< T >::CreateNewOnBuffer(
        typename TParticles< T >::buffer_t& SIXTRL_RESTRICT_REF buffer,
        typename TParticles< T >::size_type const num_particles )
    {
        using _this_t = TParticles< T >;

        static_assert( std::is_trivial< _this_t >::value, "" );
        static_assert( std::is_standard_layout< _this_t >::value, "" );

        size_t const real_size    = sizeof( real_t );
        size_t const index_size   = sizeof( index_t );
        size_t const num_dataptrs = NS(PARTICLES_NUM_DATAPTRS);

        size_t const offsets[] =
        {
            offsetof( _this_t, beta0 ),
            offsetof( _this_t, mass0 ),
            offsetof( _this_t, beta0 ),
            offsetof( _this_t, gamma0 ),
            offsetof( _this_t, p0c ),

            offsetof( _this_t, s ),
            offsetof( _this_t, x ),
            offsetof( _this_t, y ),
            offsetof( _this_t, px ),
            offsetof( _this_t, py ),
            offsetof( _this_t, zeta ),

            offsetof( _this_t, psigma ),
            offsetof( _this_t, delta ),
            offsetof( _this_t, rpp ),
            offsetof( _this_t, rvv ),
            offsetof( _this_t, chi ),

            offsetof( _this_t, particle_id ),
            offsetof( _this_t, at_element_id ),
            offsetof( _this_t, at_turn ),
            offsetof( _this_t, state )
        };

        size_t const sizes[] =
        {
            real_size,  real_size,  real_size,  real_size,  real_size,
            real_size,  real_size,  real_size,
            real_size,  real_size,  real_size,
            real_size,  real_size,  real_size,  real_size,  real_size,
            index_size, index_size, index_size, index_size
        };

        size_t const counts[] =
        {
            num_particles, num_particles, num_particles,
            num_particles, num_particles,

            num_particles, num_particles, num_particles,
            num_particles, num_particles, num_particles,

            num_particles, num_particles, num_particles,
            num_particles, num_particles,

            num_particles, num_particles, num_particles, num_particles
        };

        _this_t temp;
        temp.preset();
        temp.setNumParticles( num_particles );
        type_id_t const type_id = temp.getTypeId();

        return reinterpret_cast< T* >( static_cast< uintptr_t >(
            ::NS(Object_get_begin_addr)(
                ::NS(Buffer_add_object)( &buffer, &temp, sizeof( _this_t ),
                    type_id, num_dataptrs, offsets, sizes, counts ) ) ) );
    }

    template< typename T >
    SIXTRL_INLINE  TParticles< T >* TParticles< T >::AddToBuffer(
        typename TParticles< T >::buffer_t& SIXTRL_RESTRICT_REF buffer,
        typename TParticles< T >::size_type const num_particles,
        typename TParticles< T >::real_pointer_t  q0_ptr,
        typename TParticles< T >::real_pointer_t  mass0_ptr,
        typename TParticles< T >::real_pointer_t  beta0_ptr,
        typename TParticles< T >::real_pointer_t  gamma0_ptr,
        typename TParticles< T >::real_pointer_t  p0c_ptr,
        typename TParticles< T >::real_pointer_t  s_ptr,
        typename TParticles< T >::real_pointer_t  x_ptr,
        typename TParticles< T >::real_pointer_t  y_ptr,
        typename TParticles< T >::real_pointer_t  py_ptr,
        typename TParticles< T >::real_pointer_t  px_ptr,
        typename TParticles< T >::real_pointer_t  zeta_ptr,
        typename TParticles< T >::real_pointer_t  psigma_ptr,
        typename TParticles< T >::real_pointer_t  delta_ptr,
        typename TParticles< T >::real_pointer_t  rpp_ptr,
        typename TParticles< T >::real_pointer_t  rvv_ptr,
        typename TParticles< T >::real_pointer_t  chi_ptr,
        typename TParticles< T >::index_pointer_t particle_id_ptr  ,
        typename TParticles< T >::index_pointer_t at_element_id_ptr,
        typename TParticles< T >::index_pointer_t at_turn_ptr,
        typename TParticles< T >::index_pointer_t state_ptr )
    {
        using _this_t = TParticles< T >;

        static_assert( std::is_trivial< _this_t >::value, "" );
        static_assert( std::is_standard_layout< _this_t >::value, "" );

        size_t const real_size    = sizeof( real_t );
        size_t const index_size   = sizeof( index_t );
        size_t const num_dataptrs = NS(PARTICLES_NUM_DATAPTRS);

        size_t const offsets[] =
        {
            offsetof( _this_t, beta0 ),
            offsetof( _this_t, mass0 ),
            offsetof( _this_t, beta0 ),
            offsetof( _this_t, gamma0 ),
            offsetof( _this_t, p0c ),

            offsetof( _this_t, s ),
            offsetof( _this_t, x ),
            offsetof( _this_t, y ),
            offsetof( _this_t, px ),
            offsetof( _this_t, py ),
            offsetof( _this_t, zeta ),

            offsetof( _this_t, psigma ),
            offsetof( _this_t, delta ),
            offsetof( _this_t, rpp ),
            offsetof( _this_t, rvv ),
            offsetof( _this_t, chi ),

            offsetof( _this_t, particle_id ),
            offsetof( _this_t, at_element_id ),
            offsetof( _this_t, at_turn ),
            offsetof( _this_t, state )
        };

        size_t const sizes[] =
        {
            real_size,  real_size,  real_size,  real_size,  real_size,
            real_size,  real_size,  real_size,
            real_size,  real_size,  real_size,
            real_size,  real_size,  real_size,  real_size,  real_size,
            index_size, index_size, index_size, index_size
        };

        size_t const counts[] =
        {
            num_particles, num_particles, num_particles,
            num_particles, num_particles,

            num_particles, num_particles, num_particles,
            num_particles, num_particles, num_particles,

            num_particles, num_particles, num_particles,
            num_particles, num_particles,

            num_particles, num_particles, num_particles, num_particles
        };

        _this_t temp;
        temp.setNumParticles( num_particles );
        temp.assignQ0Ptr( q0_ptr );
        temp.assignMass0Ptr( mass0_ptr );
        temp.assignBeta0Ptr( beta0_ptr );
        temp.assignGamma0Ptr( gamma0_ptr );
        temp.assignP0cPtr( p0c_ptr );
        temp.assignSPtr( s_ptr );
        temp.assignXPtr( x_ptr );
        temp.assignYPtr( y_ptr );
        temp.assignPxPtr( px_ptr );
        temp.assignPyPtr( py_ptr );
        temp.assignZetaPtr( zeta_ptr );
        temp.assignPSigmaPtr( psigma_ptr );
        temp.assignDeltaPtr( delta_ptr );
        temp.assignRppPtr( rpp_ptr );
        temp.assignRvvPtr( rvv_ptr );
        temp.assignChiPtr( chi_ptr );
        temp.assignParticleIdPtr( particle_id_ptr );
        temp.assignAtElementIdPtr( at_element_id_ptr );
        temp.assignAtTurnPtr( at_turn_ptr );
        temp.assignStatePtr( state_ptr );

        type_id_t const type_id = temp.getTypeId();

        return reinterpret_cast< T* >( static_cast< uintptr_t >(
            ::NS(Object_get_begin_addr)(
                ::NS(Buffer_add_object)( &buffer, &temp, sizeof( _this_t ),
                    type_id, num_dataptrs, offsets, sizes, counts ) ) ) );
    }

    /* ----------------------------------------------------------------- */

    template< typename T >
    SIXTRL_INLINE typename TParticles< T >::num_elements_t
    TParticles< T >::getNumParticles() const SIXTRL_NOEXCEPT
    {
        return this->num_particles;
    }

    template< typename T >
    SIXTRL_INLINE void TParticles< T >::setNumParticles(
            typename TParticles< T >::num_elements_t const num_particles
        ) SIXTRL_NOEXCEPT
    {
        this->num_particles = num_particles;
        return;
    }

    template< typename T >
    SIXTRL_INLINE void TParticles< T >::preset() SIXTRL_NOEXCEPT
    {
        this->setNumParticles( num_elements_t{ 0 } );

        this->assignQ0Ptr( nullptr );
        this->assignMass0Ptr( nullptr );
        this->assignBeta0Ptr( nullptr );
        this->assignGamma0Ptr( nullptr );
        this->assignP0cPtr( nullptr );

        this->assignSPtr( nullptr );
        this->assignXPtr( nullptr );
        this->assignYPtr( nullptr );
        this->assignPxPtr( nullptr );
        this->assignPyPtr( nullptr );
        this->assignZetaPtr( nullptr );

        this->assignPSigmaPtr( nullptr );
        this->assignDeltaPtr( nullptr );
        this->assignRppPtr( nullptr );
        this->assignRvvPtr( nullptr );
        this->assignChiPtr( nullptr );

        this->assignParticleIdPtr( nullptr );
        this->assignAtElementIdPtr( nullptr );
        this->assignAtTurnPtr( nullptr );
        this->assignStatePtr( nullptr );

        return;
    }

    /* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

    template< typename T >
    SIXTRL_INLINE typename TParticles< T >::const_real_pointer_t
    TParticles< T >::getQ0() const SIXTRL_NOEXCEPT
    {
        return this->beta0;
    }

    template< typename T >
    SIXTRL_INLINE typename TParticles< T >::real_pointer_t
    TParticles< T >::getQ0() SIXTRL_NOEXCEPT
    {
        return this->beta0;
    }

    template< typename T >
    SIXTRL_INLINE typename TParticles< T >::real_t
    TParticles< T >::getQ0Value(
        typename TParticles< T >::index_t const index ) const SIXTRL_NOEXCEPT
    {
        return this->realValueGetterFn( this->beta0, index );
    }

    template< typename T >
    template< typename Iter >
    SIXTRL_INLINE void TParticles< T >::setQ0( Iter begin,
                                               Iter end ) SIXTRL_NOEXCEPT
    {
        using elem_t = typename TParticles< T >::num_elements_t;
        elem_t const in_num_particles = std::distance( begin, end );

        if( in_num_particles <= this->getNumParticles() )
        {
            std::copy( begin, end, this->getQ0() );
        }

        return;
    }

    template< typename T >
    SIXTRL_INLINE void TParticles< T >::setQ0Value(
        typename TParticles< T >::index_t const index,
        typename TParticles< T >::real_t const value ) SIXTRL_NOEXCEPT
    {
        this->realValueSetterFn( this->beta0, index, value );
        return;
    }

    template< typename T >
    SIXTRL_INLINE  void TParticles< T >::assignQ0Ptr(
        typename TParticles< T >::real_pointer_t ptr ) SIXTRL_NOEXCEPT
    {
        this->beta0 = ptr;
        return;
    }

    /* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

    template< typename T >
    SIXTRL_INLINE typename TParticles< T >::const_real_pointer_t
    TParticles< T >::getMass0() const SIXTRL_NOEXCEPT
    {
        return this->mass0;
    }

    template< typename T >
    SIXTRL_INLINE typename TParticles< T >::real_pointer_t
    TParticles< T >::getMass0() SIXTRL_NOEXCEPT
    {
        return this->mass0;
    }

    template< typename T >
    SIXTRL_INLINE typename TParticles< T >::real_t
    TParticles< T >::getMass0Value(
        typename TParticles< T >::index_t const index ) const SIXTRL_NOEXCEPT
    {
        return this->realValueGetterFn( this->mass0, index );
    }

    template< typename T >
    template< typename Iter >
    SIXTRL_INLINE void TParticles< T >::setMass0(
        Iter begin, Iter end ) SIXTRL_NOEXCEPT
    {
        using elem_t = typename TParticles< T >::num_elements_t;
        elem_t const in_num_particles = std::distance( begin, end );

        if( in_num_particles <= this->getNumParticles() )
        {
            std::copy( begin, end, this->getMass0() );
        }

        return;
    }

    template< typename T >
    SIXTRL_INLINE void TParticles< T >::setMass0Value(
        typename TParticles< T >::index_t const index,
        typename TParticles< T >::real_t const value ) SIXTRL_NOEXCEPT
    {
        this->realValueSetterFn( this->mass0, index, value );
        return;
    }

    template< typename T >
    SIXTRL_INLINE  void TParticles< T >::assignMass0Ptr(
        typename TParticles< T >::real_pointer_t ptr ) SIXTRL_NOEXCEPT
    {
        this->mass0 = ptr;
        return;
    }

    /* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

    template< typename T >
    SIXTRL_INLINE typename TParticles< T >::const_real_pointer_t
    TParticles< T >::getBeta0() const SIXTRL_NOEXCEPT
    {
        return this->beta0;
    }

    template< typename T >
    SIXTRL_INLINE typename TParticles< T >::real_pointer_t
    TParticles< T >::getBeta0() SIXTRL_NOEXCEPT
    {
        return this->beta0;
    }

    template< typename T >
    SIXTRL_INLINE typename TParticles< T >::real_t
    TParticles< T >::getBeta0Value(
        typename TParticles< T >::index_t const index ) const SIXTRL_NOEXCEPT
    {
        return this->realValueGetterFn( this->beta0, index );
    }

    template< typename T >
    template< typename Iter >
    SIXTRL_INLINE void TParticles< T >::setBeta0( Iter begin,
                                               Iter end ) SIXTRL_NOEXCEPT
    {
        using elem_t = typename TParticles< T >::num_elements_t;
        elem_t const in_num_particles = std::distance( begin, end );

        if( in_num_particles <= this->getNumParticles() )
        {
            std::copy( begin, end, this->getBeta0() );
        }

        return;
    }

    template< typename T >
    SIXTRL_INLINE void TParticles< T >::setBeta0Value(
        typename TParticles< T >::index_t const index,
        typename TParticles< T >::real_t const value ) SIXTRL_NOEXCEPT
    {
        this->realValueSetterFn( this->beta0, index, value );
        return;
    }

    template< typename T >
    SIXTRL_INLINE  void TParticles< T >::assignBeta0Ptr(
        typename TParticles< T >::real_pointer_t ptr ) SIXTRL_NOEXCEPT
    {
        this->beta0 = ptr;
        return;
    }

    /* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

    template< typename T >
    SIXTRL_INLINE typename TParticles< T >::const_real_pointer_t
    TParticles< T >::getGamma0() const SIXTRL_NOEXCEPT
    {
        return this->gamma0;
    }

    template< typename T >
    SIXTRL_INLINE typename TParticles< T >::real_pointer_t
    TParticles< T >::getGamma0() SIXTRL_NOEXCEPT
    {
        return this->gamma0;
    }

    template< typename T >
    SIXTRL_INLINE typename TParticles< T >::real_t
    TParticles< T >::getGamma0Value(
        typename TParticles< T >::index_t const index ) const SIXTRL_NOEXCEPT
    {
        return this->realValueGetterFn( this->gamma0, index );
    }

    template< typename T >
    template< typename Iter >
    SIXTRL_INLINE void TParticles< T >::setGamma0(
        Iter begin, Iter end ) SIXTRL_NOEXCEPT
    {
        using elem_t = typename TParticles< T >::num_elements_t;
        elem_t const in_num_particles = std::distance( begin, end );

        if( in_num_particles <= this->getNumParticles() )
        {
            std::copy( begin, end, this->getGamma0() );
        }

        return;
    }

    template< typename T >
    SIXTRL_INLINE void TParticles< T >::setGamma0Value(
        typename TParticles< T >::index_t const index,
        typename TParticles< T >::real_t const value ) SIXTRL_NOEXCEPT
    {
        this->realValueSetterFn( this->gamma0, index, value );
        return;
    }

    template< typename T >
    SIXTRL_INLINE  void TParticles< T >::assignGamma0Ptr(
        typename TParticles< T >::real_pointer_t ptr ) SIXTRL_NOEXCEPT
    {
        this->gamma0 = ptr;
        return;
    }

    /* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

    template< typename T >
    SIXTRL_INLINE typename TParticles< T >::const_real_pointer_t
    TParticles< T >::getP0c() const SIXTRL_NOEXCEPT
    {
        return this->p0c;
    }

    template< typename T >
    SIXTRL_INLINE typename TParticles< T >::real_pointer_t
    TParticles< T >::getP0c() SIXTRL_NOEXCEPT
    {
        return this->p0c;
    }

    template< typename T >
    SIXTRL_INLINE typename TParticles< T >::real_t
    TParticles< T >::getP0cValue(
        typename TParticles< T >::index_t const index ) const SIXTRL_NOEXCEPT
    {
        return this->realValueGetterFn( this->p0c, index );
    }

    template< typename T >
    template< typename Iter >
    SIXTRL_INLINE void TParticles< T >::setP0c( Iter begin,
                                               Iter end ) SIXTRL_NOEXCEPT
    {
        using elem_t = typename TParticles< T >::num_elements_t;
        elem_t const in_num_particles = std::distance( begin, end );

        if( in_num_particles <= this->getNumParticles() )
        {
            std::copy( begin, end, this->getP0c() );
        }

        return;
    }

    template< typename T >
    SIXTRL_INLINE void TParticles< T >::setP0cValue(
        typename TParticles< T >::index_t const index,
        typename TParticles< T >::real_t const value ) SIXTRL_NOEXCEPT
    {
        this->realValueSetterFn( this->p0c, index, value );
        return;
    }

    template< typename T >
    SIXTRL_INLINE  void TParticles< T >::assignP0cPtr(
        typename TParticles< T >::real_pointer_t ptr ) SIXTRL_NOEXCEPT
    {
        this->p0c = ptr;
        return;
    }

    /* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

    template< typename T >
    SIXTRL_INLINE typename TParticles< T >::const_real_pointer_t
    TParticles< T >::getS() const SIXTRL_NOEXCEPT
    {
        return this->s;
    }

    template< typename T >
    SIXTRL_INLINE typename TParticles< T >::real_pointer_t
    TParticles< T >::getS() SIXTRL_NOEXCEPT
    {
        return this->s;
    }

    template< typename T >
    SIXTRL_INLINE typename TParticles< T >::real_t
    TParticles< T >::getSValue(
        typename TParticles< T >::index_t const index ) const SIXTRL_NOEXCEPT
    {
        return this->realValueGetterFn( this->s, index );
    }

    template< typename T >
    template< typename Iter >
    SIXTRL_INLINE void TParticles< T >::setS( Iter begin,
                                               Iter end ) SIXTRL_NOEXCEPT
    {
        using elem_t = typename TParticles< T >::num_elements_t;
        elem_t const in_num_particles = std::distance( begin, end );

        if( in_num_particles <= this->getNumParticles() )
        {
            std::copy( begin, end, this->getS() );
        }

        return;
    }

    template< typename T >
    SIXTRL_INLINE void TParticles< T >::setSValue(
        typename TParticles< T >::index_t const index,
        typename TParticles< T >::real_t const value ) SIXTRL_NOEXCEPT
    {
        this->realValueSetterFn( this->s, index, value );
        return;
    }

    template< typename T >
    SIXTRL_INLINE  void TParticles< T >::assignSPtr(
        typename TParticles< T >::real_pointer_t ptr ) SIXTRL_NOEXCEPT
    {
        this->s = ptr;
        return;
    }

    /* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

    template< typename T >
    SIXTRL_INLINE typename TParticles< T >::const_real_pointer_t
    TParticles< T >::getX() const SIXTRL_NOEXCEPT
    {
        return this->x;
    }

    template< typename T >
    SIXTRL_INLINE typename TParticles< T >::real_pointer_t
    TParticles< T >::getX() SIXTRL_NOEXCEPT
    {
        return this->x;
    }

    template< typename T >
    SIXTRL_INLINE typename TParticles< T >::real_t
    TParticles< T >::getXValue(
        typename TParticles< T >::index_t const index ) const SIXTRL_NOEXCEPT
    {
        return this->realValueGetterFn( this->x, index );
    }

    template< typename T >
    template< typename Iter >
    SIXTRL_INLINE void TParticles< T >::setX( Iter begin,
                                               Iter end ) SIXTRL_NOEXCEPT
    {
        using elem_t = typename TParticles< T >::num_elements_t;
        elem_t const in_num_particles = std::distance( begin, end );

        if( in_num_particles <= this->getNumParticles() )
        {
            std::copy( begin, end, this->getX() );
        }

        return;
    }

    template< typename T >
    SIXTRL_INLINE void TParticles< T >::setXValue(
        typename TParticles< T >::index_t const index,
        typename TParticles< T >::real_t const value ) SIXTRL_NOEXCEPT
    {
        this->realValueSetterFn( this->x, index, value );
        return;
    }

    template< typename T >
    SIXTRL_INLINE  void TParticles< T >::assignXPtr(
        typename TParticles< T >::real_pointer_t ptr ) SIXTRL_NOEXCEPT
    {
        this->x = ptr;
        return;
    }

    /* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

    template< typename T >
    SIXTRL_INLINE typename TParticles< T >::const_real_pointer_t
    TParticles< T >::getY() const SIXTRL_NOEXCEPT
    {
        return this->y;
    }

    template< typename T >
    SIXTRL_INLINE typename TParticles< T >::real_pointer_t
    TParticles< T >::getY() SIXTRL_NOEXCEPT
    {
        return this->y;
    }

    template< typename T >
    SIXTRL_INLINE typename TParticles< T >::real_t
    TParticles< T >::getYValue(
        typename TParticles< T >::index_t const index ) const SIXTRL_NOEXCEPT
    {
        return this->realValueGetterFn( this->y, index );
    }

    template< typename T >
    template< typename Iter >
    SIXTRL_INLINE void TParticles< T >::setY( Iter begin,
                                               Iter end ) SIXTRL_NOEXCEPT
    {
        using elem_t = typename TParticles< T >::num_elements_t;
        elem_t const in_num_particles = std::distance( begin, end );

        if( in_num_particles <= this->getNumParticles() )
        {
            std::copy( begin, end, this->getY() );
        }

        return;
    }

    template< typename T >
    SIXTRL_INLINE void TParticles< T >::setYValue(
        typename TParticles< T >::index_t const index,
        typename TParticles< T >::real_t const value ) SIXTRL_NOEXCEPT
    {
        this->realValueSetterFn( this->y, index, value );
        return;
    }

    template< typename T >
    SIXTRL_INLINE  void TParticles< T >::assignYPtr(
        typename TParticles< T >::real_pointer_t ptr ) SIXTRL_NOEXCEPT
    {
        this->y = ptr;
        return;
    }

    /* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

    template< typename T >
    SIXTRL_INLINE typename TParticles< T >::const_real_pointer_t
    TParticles< T >::getPx() const SIXTRL_NOEXCEPT
    {
        return this->px;
    }

    template< typename T >
    SIXTRL_INLINE typename TParticles< T >::real_pointer_t
    TParticles< T >::getPx() SIXTRL_NOEXCEPT
    {
        return this->px;
    }

    template< typename T >
    SIXTRL_INLINE typename TParticles< T >::real_t
    TParticles< T >::getPxValue(
        typename TParticles< T >::index_t const index ) const SIXTRL_NOEXCEPT
    {
        return this->realValueGetterFn( this->px, index );
    }

    template< typename T >
    template< typename Iter >
    SIXTRL_INLINE void TParticles< T >::setPx( Iter begin,
                                               Iter end ) SIXTRL_NOEXCEPT
    {
        using elem_t = typename TParticles< T >::num_elements_t;
        elem_t const in_num_particles = std::distance( begin, end );

        if( in_num_particles <= this->getNumParticles() )
        {
            std::copy( begin, end, this->getPx() );
        }

        return;
    }

    template< typename T >
    SIXTRL_INLINE void TParticles< T >::setPxValue(
        typename TParticles< T >::index_t const index,
        typename TParticles< T >::real_t const value ) SIXTRL_NOEXCEPT
    {
        this->realValueSetterFn( this->px, index, value );
        return;
    }

    template< typename T >
    SIXTRL_INLINE  void TParticles< T >::assignPxPtr(
        typename TParticles< T >::real_pointer_t ptr ) SIXTRL_NOEXCEPT
    {
        this->px = ptr;
        return;
    }

    /* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

    template< typename T >
    SIXTRL_INLINE typename TParticles< T >::const_real_pointer_t
    TParticles< T >::getPy() const SIXTRL_NOEXCEPT
    {
        return this->py;
    }

    template< typename T >
    SIXTRL_INLINE typename TParticles< T >::real_pointer_t
    TParticles< T >::getPy() SIXTRL_NOEXCEPT
    {
        return this->py;
    }

    template< typename T >
    SIXTRL_INLINE typename TParticles< T >::real_t
    TParticles< T >::getPyValue(
        typename TParticles< T >::index_t const index ) const SIXTRL_NOEXCEPT
    {
        return this->realValueGetterFn( this->py, index );
    }

    template< typename T >
    template< typename Iter >
    SIXTRL_INLINE void TParticles< T >::setPy( Iter begin,
                                               Iter end ) SIXTRL_NOEXCEPT
    {
        using elem_t = typename TParticles< T >::num_elements_t;
        elem_t const in_num_particles = std::distance( begin, end );

        if( in_num_particles <= this->getNumParticles() )
        {
            std::copy( begin, end, this->getPy() );
        }

        return;
    }

    template< typename T >
    SIXTRL_INLINE void TParticles< T >::setPyValue(
        typename TParticles< T >::index_t const index,
        typename TParticles< T >::real_t const value ) SIXTRL_NOEXCEPT
    {
        this->realValueSetterFn( this->py, index, value );
        return;
    }

    template< typename T >
    SIXTRL_INLINE  void TParticles< T >::assignPyPtr(
        typename TParticles< T >::real_pointer_t ptr ) SIXTRL_NOEXCEPT
    {
        this->py = ptr;
        return;
    }

    /* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

    template< typename T >
    SIXTRL_INLINE typename TParticles< T >::const_real_pointer_t
    TParticles< T >::getZeta() const SIXTRL_NOEXCEPT
    {
        return this->zeta;
    }

    template< typename T >
    SIXTRL_INLINE typename TParticles< T >::real_pointer_t
    TParticles< T >::getZeta() SIXTRL_NOEXCEPT
    {
        return this->zeta;
    }

    template< typename T >
    SIXTRL_INLINE typename TParticles< T >::real_t
    TParticles< T >::getZetaValue(
        typename TParticles< T >::index_t const index ) const SIXTRL_NOEXCEPT
    {
        return this->realValueGetterFn( this->zeta, index );
    }

    template< typename T >
    template< typename Iter >
    SIXTRL_INLINE void TParticles< T >::setZeta( Iter begin,
                                               Iter end ) SIXTRL_NOEXCEPT
    {
        using elem_t = typename TParticles< T >::num_elements_t;
        elem_t const in_num_particles = std::distance( begin, end );

        if( in_num_particles <= this->getNumParticles() )
        {
            std::copy( begin, end, this->getZeta() );
        }

        return;
    }

    template< typename T >
    SIXTRL_INLINE void TParticles< T >::setZetaValue(
        typename TParticles< T >::index_t const index,
        typename TParticles< T >::real_t const value ) SIXTRL_NOEXCEPT
    {
        this->realValueSetterFn( this->zeta, index, value );
        return;
    }

    template< typename T >
    SIXTRL_INLINE  void TParticles< T >::assignZetaPtr(
        typename TParticles< T >::real_pointer_t ptr ) SIXTRL_NOEXCEPT
    {
        this->zeta = ptr;
        return;
    }

    /* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

    template< typename T >
    SIXTRL_INLINE typename TParticles< T >::const_real_pointer_t
    TParticles< T >::getPSigma() const SIXTRL_NOEXCEPT
    {
        return this->psigma;
    }

    template< typename T >
    SIXTRL_INLINE typename TParticles< T >::real_pointer_t
    TParticles< T >::getPSigma() SIXTRL_NOEXCEPT
    {
        return this->psigma;
    }

    template< typename T >
    SIXTRL_INLINE typename TParticles< T >::real_t
    TParticles< T >::getPSigmaValue(
        typename TParticles< T >::index_t const index ) const SIXTRL_NOEXCEPT
    {
        return this->realValueGetterFn( this->psigma, index );
    }

    template< typename T >
    template< typename Iter >
    SIXTRL_INLINE void TParticles< T >::setPSigma( Iter begin,
                                               Iter end ) SIXTRL_NOEXCEPT
    {
        using elem_t = typename TParticles< T >::num_elements_t;
        elem_t const in_num_particles = std::distance( begin, end );

        if( in_num_particles <= this->getNumParticles() )
        {
            std::copy( begin, end, this->getPSigma() );
        }

        return;
    }

    template< typename T >
    SIXTRL_INLINE void TParticles< T >::setPSigmaValue(
        typename TParticles< T >::index_t const index,
        typename TParticles< T >::real_t const value ) SIXTRL_NOEXCEPT
    {
        this->realValueSetterFn( this->psigma, index, value );
        return;
    }

    template< typename T >
    SIXTRL_INLINE  void TParticles< T >::assignPSigmaPtr(
        typename TParticles< T >::real_pointer_t ptr ) SIXTRL_NOEXCEPT
    {
        this->psigma = ptr;
        return;
    }

    /* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

    template< typename T >
    SIXTRL_INLINE typename TParticles< T >::const_real_pointer_t
    TParticles< T >::getDelta() const SIXTRL_NOEXCEPT
    {
        return this->delta;
    }

    template< typename T >
    SIXTRL_INLINE typename TParticles< T >::real_pointer_t
    TParticles< T >::getDelta() SIXTRL_NOEXCEPT
    {
        return this->delta;
    }

    template< typename T >
    SIXTRL_INLINE typename TParticles< T >::real_t
    TParticles< T >::getDeltaValue(
        typename TParticles< T >::index_t const index ) const SIXTRL_NOEXCEPT
    {
        return this->realValueGetterFn( this->delta, index );
    }

    template< typename T >
    template< typename Iter >
    SIXTRL_INLINE void TParticles< T >::setDelta( Iter begin,
                                               Iter end ) SIXTRL_NOEXCEPT
    {
        using elem_t = typename TParticles< T >::num_elements_t;
        elem_t const in_num_particles = std::distance( begin, end );

        if( in_num_particles <= this->getNumParticles() )
        {
            std::copy( begin, end, this->getDelta() );
        }

        return;
    }

    template< typename T >
    SIXTRL_INLINE void TParticles< T >::setDeltaValue(
        typename TParticles< T >::index_t const index,
        typename TParticles< T >::real_t const value ) SIXTRL_NOEXCEPT
    {
        this->realValueSetterFn( this->delta, index, value );
        return;
    }

    template< typename T >
    SIXTRL_INLINE  void TParticles< T >::assignDeltaPtr(
        typename TParticles< T >::real_pointer_t ptr ) SIXTRL_NOEXCEPT
    {
        this->delta = ptr;
        return;
    }

    /* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

    template< typename T >
    SIXTRL_INLINE typename TParticles< T >::const_real_pointer_t
    TParticles< T >::getRpp() const SIXTRL_NOEXCEPT
    {
        return this->rpp;
    }

    template< typename T >
    SIXTRL_INLINE typename TParticles< T >::real_pointer_t
    TParticles< T >::getRpp() SIXTRL_NOEXCEPT
    {
        return this->rpp;
    }

    template< typename T >
    SIXTRL_INLINE typename TParticles< T >::real_t
    TParticles< T >::getRppValue(
        typename TParticles< T >::index_t const index ) const SIXTRL_NOEXCEPT
    {
        return this->realValueGetterFn( this->rpp, index );
    }

    template< typename T >
    template< typename Iter >
    SIXTRL_INLINE void TParticles< T >::setRpp( Iter begin,
                                               Iter end ) SIXTRL_NOEXCEPT
    {
        using elem_t = typename TParticles< T >::num_elements_t;
        elem_t const in_num_particles = std::distance( begin, end );

        if( in_num_particles <= this->getNumParticles() )
        {
            std::copy( begin, end, this->getRpp() );
        }

        return;
    }

    template< typename T >
    SIXTRL_INLINE void TParticles< T >::setRppValue(
        typename TParticles< T >::index_t const index,
        typename TParticles< T >::real_t const value ) SIXTRL_NOEXCEPT
    {
        this->realValueSetterFn( this->rpp, index, value );
        return;
    }

    template< typename T >
    SIXTRL_INLINE  void TParticles< T >::assignRppPtr(
        typename TParticles< T >::real_pointer_t ptr ) SIXTRL_NOEXCEPT
    {
        this->rpp = ptr;
        return;
    }

    /* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

    template< typename T >
    SIXTRL_INLINE typename TParticles< T >::const_real_pointer_t
    TParticles< T >::getRvv() const SIXTRL_NOEXCEPT
    {
        return this->rvv;
    }

    template< typename T >
    SIXTRL_INLINE typename TParticles< T >::real_pointer_t
    TParticles< T >::getRvv() SIXTRL_NOEXCEPT
    {
        return this->rvv;
    }

    template< typename T >
    SIXTRL_INLINE typename TParticles< T >::real_t
    TParticles< T >::getRvvValue(
        typename TParticles< T >::index_t const index ) const SIXTRL_NOEXCEPT
    {
        return this->realValueGetterFn( this->rvv, index );
    }

    template< typename T >
    template< typename Iter >
    SIXTRL_INLINE void TParticles< T >::setRvv( Iter begin,
                                               Iter end ) SIXTRL_NOEXCEPT
    {
        using elem_t = typename TParticles< T >::num_elements_t;
        elem_t const in_num_particles = std::distance( begin, end );

        if( in_num_particles <= this->getNumParticles() )
        {
            std::copy( begin, end, this->getRvv() );
        }

        return;
    }

    template< typename T >
    SIXTRL_INLINE void TParticles< T >::setRvvValue(
        typename TParticles< T >::index_t const index,
        typename TParticles< T >::real_t const value ) SIXTRL_NOEXCEPT
    {
        this->realValueSetterFn( this->rvv, index, value );
        return;
    }

    template< typename T >
    SIXTRL_INLINE  void TParticles< T >::assignRvvPtr(
        typename TParticles< T >::real_pointer_t ptr ) SIXTRL_NOEXCEPT
    {
        this->rvv = ptr;
        return;
    }

    /* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

    template< typename T >
    SIXTRL_INLINE typename TParticles< T >::const_real_pointer_t
    TParticles< T >::getChi() const SIXTRL_NOEXCEPT
    {
        return this->chi;
    }

    template< typename T >
    SIXTRL_INLINE typename TParticles< T >::real_pointer_t
    TParticles< T >::getChi() SIXTRL_NOEXCEPT
    {
        return this->chi;
    }

    template< typename T >
    SIXTRL_INLINE typename TParticles< T >::real_t
    TParticles< T >::getChiValue(
        typename TParticles< T >::index_t const index ) const SIXTRL_NOEXCEPT
    {
        return this->realValueGetterFn( this->chi, index );
    }

    template< typename T >
    template< typename Iter >
    SIXTRL_INLINE void TParticles< T >::setChi( Iter begin,
                                               Iter end ) SIXTRL_NOEXCEPT
    {
        using elem_t = typename TParticles< T >::num_elements_t;
        elem_t const in_num_particles = std::distance( begin, end );

        if( in_num_particles <= this->getNumParticles() )
        {
            std::copy( begin, end, this->getChi() );
        }

        return;
    }

    template< typename T >
    SIXTRL_INLINE void TParticles< T >::setChiValue(
        typename TParticles< T >::index_t const index,
        typename TParticles< T >::real_t const value ) SIXTRL_NOEXCEPT
    {
        this->realValueSetterFn( this->chi, index, value );
        return;
    }

    template< typename T >
    SIXTRL_INLINE  void TParticles< T >::assignChiPtr(
        typename TParticles< T >::real_pointer_t ptr ) SIXTRL_NOEXCEPT
    {
        this->chi = ptr;
        return;
    }

    /* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

    template< typename T >
    SIXTRL_INLINE typename TParticles< T >::const_index_pointer_t
    TParticles< T >::getParticleId() const SIXTRL_NOEXCEPT
    {
        return this->particle_id;
    }

    template< typename T >
    SIXTRL_INLINE typename TParticles< T >::index_pointer_t
    TParticles< T >::getParticleId() SIXTRL_NOEXCEPT
    {
        return this->particle_id;
    }

    template< typename T >
    SIXTRL_INLINE typename TParticles< T >::index_t
    TParticles< T >::getParticleIdValue(
        typename TParticles< T >::index_t const index ) const SIXTRL_NOEXCEPT
    {
        return this->indexValueGetterFn( this->particle_id, index );
    }

    template< typename T >
    template< typename Iter >
    SIXTRL_INLINE void TParticles< T >::setParticleId( Iter begin,
                                                  Iter end ) SIXTRL_NOEXCEPT
    {
        using elem_t = typename TParticles< T >::num_elements_t;
        elem_t const in_num_particles = std::distance( begin, end );

        if( in_num_particles <= this->getNumParticles() )
        {
            std::copy( begin, end, this->getParticleId() );
        }

        return;
    }

    template< typename T >
    SIXTRL_INLINE void TParticles< T >::setParticleIdValue(
        typename TParticles< T >::index_t const index,
        typename TParticles< T >::index_t const value ) SIXTRL_NOEXCEPT
    {
        this->indexValueSetterFn( this->particle_id, index, value );
        return;
    }

    template< typename T >
    SIXTRL_INLINE void TParticles< T >::assignParticleIdPtr(
        typename TParticles< T >::index_pointer_t ptr ) SIXTRL_NOEXCEPT
    {
        this->particle_id = ptr;
        return;
    }

    /* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

    template< typename T >
    SIXTRL_INLINE typename TParticles< T >::const_index_pointer_t
    TParticles< T >::getAtElementId() const SIXTRL_NOEXCEPT
    {
        return this->at_element_id;
    }

    template< typename T >
    SIXTRL_INLINE typename TParticles< T >::index_pointer_t
    TParticles< T >::getAtElementId() SIXTRL_NOEXCEPT
    {
        return this->at_element_id;
    }

    template< typename T >
    SIXTRL_INLINE typename TParticles< T >::index_t
    TParticles< T >::getAtElementIdValue(
        typename TParticles< T >::index_t const index ) const SIXTRL_NOEXCEPT
    {
        return this->indexValueGetterFn( this->at_element_id, index );
    }

    template< typename T >
    template< typename Iter >
    SIXTRL_INLINE void TParticles< T >::setAtElementId( Iter begin,
                                                  Iter end ) SIXTRL_NOEXCEPT
    {
        using elem_t = typename TParticles< T >::num_elements_t;
        elem_t const in_num_particles = std::distance( begin, end );

        if( in_num_particles <= this->getNumParticles() )
        {
            std::copy( begin, end, this->getAtElementId() );
        }

        return;
    }

    template< typename T >
    SIXTRL_INLINE void TParticles< T >::setAtElementIdValue(
        typename TParticles< T >::index_t const index,
        typename TParticles< T >::index_t const value ) SIXTRL_NOEXCEPT
    {
        this->indexValueSetterFn( this->at_element_id, index, value );
        return;
    }

    template< typename T >
    SIXTRL_INLINE void TParticles< T >::assignAtElementIdPtr(
        typename TParticles< T >::index_pointer_t ptr ) SIXTRL_NOEXCEPT
    {
        this->at_element_id = ptr;
        return;
    }

    /* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

    template< typename T >
    SIXTRL_INLINE typename TParticles< T >::const_index_pointer_t
    TParticles< T >::getAtTurn() const SIXTRL_NOEXCEPT
    {
        return this->at_turn;
    }

    template< typename T >
    SIXTRL_INLINE typename TParticles< T >::index_pointer_t
    TParticles< T >::getAtTurn() SIXTRL_NOEXCEPT
    {
        return this->at_turn;
    }

    template< typename T >
    SIXTRL_INLINE typename TParticles< T >::index_t
    TParticles< T >::getAtTurnValue(
        typename TParticles< T >::index_t const index ) const SIXTRL_NOEXCEPT
    {
        return this->indexValueGetterFn( this->at_turn, index );
    }

    template< typename T >
    template< typename Iter >
    SIXTRL_INLINE void TParticles< T >::setAtTurn( Iter begin,
                                                  Iter end ) SIXTRL_NOEXCEPT
    {
        using elem_t = typename TParticles< T >::num_elements_t;
        elem_t const in_num_particles = std::distance( begin, end );

        if( in_num_particles <= this->getNumParticles() )
        {
            std::copy( begin, end, this->getAtTurn() );
        }

        return;
    }

    template< typename T >
    SIXTRL_INLINE void TParticles< T >::setAtTurnValue(
        typename TParticles< T >::index_t const index,
        typename TParticles< T >::index_t const value ) SIXTRL_NOEXCEPT
    {
        this->indexValueSetterFn( this->at_turn, index, value );
        return;
    }

    template< typename T >
    SIXTRL_INLINE void TParticles< T >::assignAtTurnPtr(
        typename TParticles< T >::index_pointer_t ptr ) SIXTRL_NOEXCEPT
    {
        this->at_turn = ptr;
        return;
    }

    /* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

    template< typename T >
    SIXTRL_INLINE typename TParticles< T >::const_index_pointer_t
    TParticles< T >::getState() const SIXTRL_NOEXCEPT
    {
        return this->state;
    }

    template< typename T >
    SIXTRL_INLINE typename TParticles< T >::index_pointer_t
    TParticles< T >::getState() SIXTRL_NOEXCEPT
    {
        return this->state;
    }

    template< typename T >
    SIXTRL_INLINE typename TParticles< T >::index_t
    TParticles< T >::getStateValue(
        typename TParticles< T >::index_t const index ) const SIXTRL_NOEXCEPT
    {
        return this->indexValueGetterFn( this->state, index );
    }

    template< typename T >
    template< typename Iter >
    SIXTRL_INLINE void TParticles< T >::setState( Iter begin,
                                                  Iter end ) SIXTRL_NOEXCEPT
    {
        using elem_t = typename TParticles< T >::num_elements_t;
        elem_t const in_num_particles = std::distance( begin, end );

        if( in_num_particles <= this->getNumParticles() )
        {
            std::copy( begin, end, this->getState() );
        }

        return;
    }

    template< typename T >
    SIXTRL_INLINE void TParticles< T >::setStateValue(
        typename TParticles< T >::index_t const index,
        typename TParticles< T >::index_t const value ) SIXTRL_NOEXCEPT
    {
        this->indexValueSetterFn( this->state, index, value );
        return;
    }

    template< typename T >
    SIXTRL_INLINE void TParticles< T >::assignStatePtr(
        typename TParticles< T >::index_pointer_t ptr ) SIXTRL_NOEXCEPT
    {
        this->state = ptr;
        return;
    }

    /* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

    template< typename T >
    SIXTRL_INLINE typename TParticles< T >::real_t
    TParticles< T >::realValueGetterFn(
        typename TParticles< T >::const_real_pointer_t SIXTRL_RESTRICT ptr,
        typename TParticles< T >::index_t const index ) SIXTRL_NOEXCEPT
    {
        SIXTRL_ASSERT( ptr != nullptr );
        SIXTRL_ASSERT( index < this->num_particles );
        return ptr[ index ];
    }

    template< typename T >
    SIXTRL_INLINE typename TParticles< T >::index_t
    TParticles< T >::indexValueGetterFn(
        typename TParticles< T >::const_index_pointer_t SIXTRL_RESTRICT ptr,
        typename TParticles< T >::index_t const index ) SIXTRL_NOEXCEPT
    {
        SIXTRL_ASSERT( ptr != nullptr );
        SIXTRL_ASSERT( index < this->num_particles );
        return ptr[ index ];
    }

    template< typename T >
    template< typename V, typename Ptr >
    SIXTRL_INLINE void TParticles< T >::valueSetterFn(
        Ptr* SIXTRL_RESTRICT ptr,
        typename TParticles< T >::index_t const index,
        V const value ) SIXTRL_NOEXCEPT
    {
        SIXTRL_ASSERT( ptr != nullptr );
        SIXTRL_ASSERT( index < this->num_particles );
        ptr[ index ] = value;
        return;
    }

    /* ===================================================================== */
    /* Specialization for TParticles< NS(particle_real_t) >: */
    /* ===================================================================== */

    SIXTRL_INLINE TParticles< NS(particle_real_t) >::type_id_t
    TParticles< NS(particle_real_t) >::getTypeId() const SIXTRL_NOEXCEPT
    {
        return NS(OBJECT_TYPE_PARTICLE);
    }

    /* ----------------------------------------------------------------- */


    SIXTRL_INLINE bool TParticles< NS(particle_real_t) >::CanAddToBuffer(
        TParticles< NS(particle_real_t) >::buffer_t& SIXTRL_RESTRICT_REF buffer,
        TParticles< NS(particle_real_t) >::size_type const num_particles,
        TParticles< NS(particle_real_t) >::size_type*
            SIXTRL_RESTRICT ptr_requ_objects,
        TParticles< NS(particle_real_t) >::size_type*
            SIXTRL_RESTRICT ptr_requ_slots,
        TParticles< NS(particle_real_t) >::size_type*
            SIXTRL_RESTRICT ptr_requ_dataptrs ) SIXTRL_NOEXCEPT
    {
        return ::NS(Particles_can_be_added)( &buffer, num_particles,
                ptr_requ_objects, ptr_requ_slots, ptr_requ_dataptrs );
    }


    SIXTRL_INLINE TParticles< NS(particle_real_t) >*
    TParticles< NS(particle_real_t) >::CreateNewOnBuffer(
        TParticles< NS(particle_real_t) >::buffer_t& SIXTRL_RESTRICT_REF buffer,
        TParticles< NS(particle_real_t) >::size_type const num_particles )
    {
        return reinterpret_cast< TParticles< NS(particle_real_t) >* >(
            ::NS(Particles_new)( &buffer, num_particles ) );
    }


    SIXTRL_INLINE TParticles< NS(particle_real_t) >*
    TParticles< NS(particle_real_t) >::AddToBuffer(
        TParticles< NS(particle_real_t) >::buffer_t& SIXTRL_RESTRICT_REF buffer,
        TParticles< NS(particle_real_t) >::size_type const num_particles,
        TParticles< NS(particle_real_t) >::real_pointer_t  q0_ptr,
        TParticles< NS(particle_real_t) >::real_pointer_t  mass0_ptr,
        TParticles< NS(particle_real_t) >::real_pointer_t  beta0_ptr,
        TParticles< NS(particle_real_t) >::real_pointer_t  gamma0_ptr,
        TParticles< NS(particle_real_t) >::real_pointer_t  p0c_ptr,
        TParticles< NS(particle_real_t) >::real_pointer_t  s_ptr,
        TParticles< NS(particle_real_t) >::real_pointer_t  x_ptr,
        TParticles< NS(particle_real_t) >::real_pointer_t  y_ptr,
        TParticles< NS(particle_real_t) >::real_pointer_t  px_ptr,
        TParticles< NS(particle_real_t) >::real_pointer_t  py_ptr,
        TParticles< NS(particle_real_t) >::real_pointer_t  zeta_ptr,
        TParticles< NS(particle_real_t) >::real_pointer_t  psigma_ptr,
        TParticles< NS(particle_real_t) >::real_pointer_t  delta_ptr,
        TParticles< NS(particle_real_t) >::real_pointer_t  rpp_ptr,
        TParticles< NS(particle_real_t) >::real_pointer_t  rvv_ptr,
        TParticles< NS(particle_real_t) >::real_pointer_t  chi_ptr,
        TParticles< NS(particle_real_t) >::index_pointer_t particle_id_ptr  ,
        TParticles< NS(particle_real_t) >::index_pointer_t at_element_id_ptr,
        TParticles< NS(particle_real_t) >::index_pointer_t at_turn_ptr,
        TParticles< NS(particle_real_t) >::index_pointer_t state_ptr )
    {
        return reinterpret_cast< TParticles< NS(particle_real_t) >* >(
            ::NS(Particles_add)( &buffer, num_particles,
                q0_ptr, mass0_ptr, beta0_ptr, gamma0_ptr, p0c_ptr,
                    s_ptr, x_ptr, y_ptr, px_ptr, py_ptr, zeta_ptr,
                        psigma_ptr, delta_ptr, rpp_ptr, rvv_ptr, chi_ptr,
                            particle_id_ptr, at_element_id_ptr, at_turn_ptr,
                                state_ptr ) );
    }

    /* ----------------------------------------------------------------- */

    SIXTRL_INLINE bool TParticles< NS(particle_real_t) >::copy(
        TParticles< NS(particle_real_t) > const&
            SIXTRL_RESTRICT_REF source ) SIXTRL_NOEXCEPT
    {
        return NS(Particles_copy)( this->getCApiPtr(), source.getCApiPtr() );
    }

    SIXTRL_INLINE bool TParticles< NS(particle_real_t) >::copy(
        SIXTRL_PARTICLE_ARGPTR_DEC NS(Particles) const*
            SIXTRL_RESTRICT source ) SIXTRL_NOEXCEPT
    {
        return NS(Particles_copy)( this->getCApiPtr(), source );
    }

    SIXTRL_INLINE bool TParticles< NS(particle_real_t) >::copySingle(
        TParticles< NS(particle_real_t) > const& SIXTRL_RESTRICT_REF source,
        TParticles< NS(particle_real_t) >::index_t const source_index,
        TParticles< NS(particle_real_t) >::index_t dest_index
    ) SIXTRL_NOEXCEPT
    {
        return NS(Particles_copy_single)(
            this->getCApiPtr(), dest_index, source.getCApiPtr(), source_index );
    }

    SIXTRL_INLINE bool TParticles< NS(particle_real_t) >::copySingle(
        SIXTRL_PARTICLE_ARGPTR_DEC NS(Particles) const* SIXTRL_RESTRICT source,
        TParticles< NS(particle_real_t) >::index_t const source_index,
        TParticles< NS(particle_real_t) >::index_t dest_index
    ) SIXTRL_NOEXCEPT
    {
        return NS(Particles_copy_single)(
            this->getCApiPtr(), dest_index, source, source_index );
    }

    SIXTRL_INLINE bool TParticles< NS(particle_real_t) >::copyRange(
        TParticles< NS(particle_real_t) > const& SIXTRL_RESTRICT_REF source,
        TParticles< NS(particle_real_t) >::index_t const src_start_idx,
        TParticles< NS(particle_real_t) >::index_t const src_end_idx,
        TParticles< NS(particle_real_t) >::index_t dst_start_idx
    ) SIXTRL_NOEXCEPT
    {
        return NS(Particles_copy_range)( this->getCApiPtr(), source.getCApiPtr(),
            src_start_idx, src_end_idx, dst_start_idx );
    }


    SIXTRL_INLINE bool TParticles< NS(particle_real_t) >::copyRange(
        SIXTRL_PARTICLE_ARGPTR_DEC NS(Particles) const* SIXTRL_RESTRICT source,
        TParticles< NS(particle_real_t) >::index_t const src_start_idx,
        TParticles< NS(particle_real_t) >::index_t const src_end_idx,
        TParticles< NS(particle_real_t) >::index_t dst_start_idx
    ) SIXTRL_NOEXCEPT
    {
        return NS(Particles_copy_range)( this->getCApiPtr(), source,
            src_start_idx, src_end_idx, dst_start_idx );
    }

    /* ----------------------------------------------------------------- */

    SIXTRL_INLINE SIXTRL_BUFFER_OBJ_DATAPTR_DEC
    TParticles< NS(particle_real_t) > const*
    TParticles< NS(particle_real_t) >::FromBuffer(
        Buffer const& SIXTRL_RESTRICT_REF buffer,
        Buffer::size_type const particle_obj_index ) SIXTRL_NOEXCEPT
    {
        using _this_t = TParticles< NS(particle_real_t) >;
        return _this_t::FromBuffer( buffer.getCApiPtr(), particle_obj_index );
    }

    SIXTRL_INLINE SIXTRL_BUFFER_OBJ_DATAPTR_DEC
    TParticles< NS(particle_real_t) > const*
    TParticles< NS(particle_real_t) >::FromBuffer(
        SIXTRL_BUFFER_ARGPTR_DEC const NS(Buffer) *const SIXTRL_RESTRICT buffer,
        NS(buffer_size_t) const particle_obj_index ) SIXTRL_NOEXCEPT
    {
        using _this_t        = TParticles< NS(particle_real_t) >;
        using object_t       = NS(Object);
        using ptr_object_t   = SIXTRL_BUFFER_OBJ_ARGPTR_DEC object_t const*;

        ptr_object_t ptr_particle_obj = reinterpret_cast< ptr_object_t >(
            static_cast< uintptr_t >( NS(Buffer_get_objects_begin_addr)(
                buffer ) ) );

        if( ( ptr_particle_obj != nullptr ) &&
            ( NS(Buffer_get_num_of_objects)( buffer ) > particle_obj_index ) )
        {
            std::advance( ptr_particle_obj, particle_obj_index );
            return _this_t::FromBufferObject( ptr_particle_obj );
        }

        return nullptr;
    }

    SIXTRL_INLINE SIXTRL_BUFFER_OBJ_DATAPTR_DEC
    TParticles< NS(particle_real_t) >*
    TParticles< NS(particle_real_t) >::FromBuffer(
        Buffer& SIXTRL_RESTRICT_REF buffer,
        Buffer::size_type const particle_obj_index ) SIXTRL_NOEXCEPT
    {
        using _this_t        = TParticles< NS(particle_real_t) >;
        using particle_t     = TParticles< NS(particle_real_t) >;
        using ptr_particle_t = SIXTRL_BUFFER_OBJ_DATAPTR_DEC particle_t*;

        Buffer const& const_buffer = buffer;

        return const_cast< ptr_particle_t >(
            _this_t::FromBuffer( const_buffer, particle_obj_index ) );
    }

    SIXTRL_INLINE SIXTRL_BUFFER_OBJ_DATAPTR_DEC
    TParticles< NS(particle_real_t) >*
    TParticles< NS(particle_real_t) >::FromBuffer(
        SIXTRL_BUFFER_ARGPTR_DEC NS(Buffer)* SIXTRL_RESTRICT buffer,
        NS(buffer_size_t) const particle_obj_index ) SIXTRL_NOEXCEPT
    {
        using _this_t        = TParticles< NS(particle_real_t) >;
        using particle_t     = TParticles< NS(particle_real_t) >;
        using ptr_particle_t = SIXTRL_BUFFER_OBJ_DATAPTR_DEC particle_t*;

        SIXTRL_BUFFER_ARGPTR_DEC NS(Buffer) const* const_buffer = buffer;

        return const_cast< ptr_particle_t >(
            _this_t::FromBuffer( const_buffer, particle_obj_index ) );
    }

    /* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

    SIXTRL_BUFFER_OBJ_DATAPTR_DEC TParticles< NS(particle_real_t) > const*
    TParticles< NS(particle_real_t) >::FromBufferObject(
        SIXTRL_BUFFER_OBJ_ARGPTR_DEC const NS(Object) *const
            SIXTRL_RESTRICT index_obj ) SIXTRL_NOEXCEPT
    {
        using _this_t        = TParticles< NS(particle_real_t) >;
        using particle_t     = TParticles< NS(particle_real_t) >;
        using ptr_particle_t = SIXTRL_BUFFER_OBJ_DATAPTR_DEC particle_t const*;

        if( ( index_obj != nullptr ) &&
            ( NS(Object_get_type_id)( index_obj ) == NS(OBJECT_TYPE_PARTICLE) ) &&
            ( NS(Object_get_size)( index_obj ) > sizeof( _this_t ) ) )
        {
            return reinterpret_cast< ptr_particle_t >( static_cast< uintptr_t >(
                NS(Object_get_begin_addr)( index_obj ) ) );
        }

        return nullptr;
    }

    SIXTRL_BUFFER_OBJ_DATAPTR_DEC TParticles< NS(particle_real_t) >*
    TParticles< NS(particle_real_t) >::FromBufferObject(
        SIXTRL_BUFFER_OBJ_ARGPTR_DEC NS(Object)*
            SIXTRL_RESTRICT index_obj ) SIXTRL_NOEXCEPT
    {
        using _this_t           = TParticles< NS(particle_real_t) >;
        using object_t          = NS(Object);
        using ptr_const_obj_t   = SIXTRL_BUFFER_OBJ_ARGPTR_DEC object_t const*;
        using particle_t        = TParticles< NS(particle_real_t) >;
        using ptr_particle_t    = SIXTRL_BUFFER_OBJ_DATAPTR_DEC particle_t*;

        ptr_const_obj_t const_index_obj = index_obj;

        return const_cast< ptr_particle_t >(
            _this_t::FromBufferObject( const_index_obj ) );
    }

    /* ----------------------------------------------------------------- */

    SIXTRL_INLINE TParticles< NS(particle_real_t) >::c_api_t const*
    TParticles< NS(particle_real_t) >::getCApiPtr() const SIXTRL_NOEXCEPT
    {
        using ptr_t = TParticles< NS(particle_real_t) >::c_api_t const*;
        return static_cast< ptr_t >( this );
    }

    SIXTRL_INLINE TParticles< NS(particle_real_t) >::c_api_t*
    TParticles< NS(particle_real_t) >::getCApiPtr() SIXTRL_NOEXCEPT
    {
        using _this_t = TParticles< NS(particle_real_t) >;
        using   ptr_t =  _this_t::c_api_t*;

        return const_cast< ptr_t >( static_cast< _this_t const& >(
            *this ).getCApiPtr() );
    }

    /* ----------------------------------------------------------------- */

    SIXTRL_INLINE TParticles< NS(particle_real_t) >::num_elements_t
    TParticles< NS(particle_real_t) >::getNumParticles() const SIXTRL_NOEXCEPT
    {
        return ::NS(Particles_get_num_of_particles)( this->getCApiPtr() );
    }

    void TParticles< NS(particle_real_t) >::setNumParticles(
        TParticles< NS(particle_real_t) >::size_type const num_particles
        ) SIXTRL_NOEXCEPT
    {
        using _this_t    = TParticles< NS(particle_real_t) >;
        using num_elem_t = _this_t::num_elements_t;

        ::NS(Particles_set_num_of_particles)( this->getCApiPtr(),
                static_cast< num_elem_t >( num_particles ) );
        return;
    }

    SIXTRL_INLINE void TParticles< NS(particle_real_t) >::preset() SIXTRL_NOEXCEPT
    {
        ::NS(Particles_preset)( this->getCApiPtr() );
    }

    /* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

    SIXTRL_INLINE TParticles< NS(particle_real_t) >::const_real_pointer_t
    TParticles< NS(particle_real_t) >::getQ0() const SIXTRL_NOEXCEPT
    {
        return ::NS(Particles_get_const_beta0)( this->getCApiPtr() );
    }


    SIXTRL_INLINE TParticles< NS(particle_real_t) >::real_pointer_t
    TParticles< NS(particle_real_t) >::getQ0() SIXTRL_NOEXCEPT
    {
        return ::NS(Particles_get_beta0)( this->getCApiPtr() );
    }


    SIXTRL_INLINE TParticles< NS(particle_real_t) >::real_t
    TParticles< NS(particle_real_t) >::getQ0Value(
        TParticles< NS(particle_real_t) >::index_t const index ) const SIXTRL_NOEXCEPT
    {
        return ::NS(Particles_get_beta0_value)( this->getCApiPtr(), index );
    }


    template< typename Iter >
    SIXTRL_INLINE void TParticles< NS(particle_real_t) >::setQ0(
        Iter begin, Iter end ) SIXTRL_NOEXCEPT
    {
        using elem_t = TParticles< NS(particle_real_t) >::num_elements_t;
        elem_t const in_num_particles = std::distance( begin, end );

        if( in_num_particles <= this->getNumParticles() )
        {
            std::copy( begin, end, this->getQ0() );
        }

        return;
    }


    SIXTRL_INLINE void TParticles< NS(particle_real_t) >::setQ0Value(
        TParticles< NS(particle_real_t) >::index_t const index,
        TParticles< NS(particle_real_t) >::real_t const value ) SIXTRL_NOEXCEPT
    {
        ::NS(Particles_set_beta0_value)( this->getCApiPtr(), index, value );
        return;
    }


    SIXTRL_INLINE void TParticles< NS(particle_real_t) >::assignQ0Ptr(
        TParticles< NS(particle_real_t) >::real_pointer_t ptr ) SIXTRL_NOEXCEPT
    {
        ::NS(Particles_assign_ptr_to_beta0)( this->getCApiPtr(), ptr );
        return;
    }

    /* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */


    SIXTRL_INLINE TParticles< NS(particle_real_t) >::const_real_pointer_t
    TParticles< NS(particle_real_t) >::getMass0() const SIXTRL_NOEXCEPT
    {
        return ::NS(Particles_get_const_mass0)( this->getCApiPtr() );
    }


    SIXTRL_INLINE TParticles< NS(particle_real_t) >::real_pointer_t
    TParticles< NS(particle_real_t) >::getMass0() SIXTRL_NOEXCEPT
    {
        return ::NS(Particles_get_mass0)( this->getCApiPtr() );
    }


    SIXTRL_INLINE TParticles< NS(particle_real_t) >::real_t
    TParticles< NS(particle_real_t) >::getMass0Value(
        TParticles< NS(particle_real_t) >::index_t const index ) const SIXTRL_NOEXCEPT
    {
        return ::NS(Particles_get_mass0_value)( this->getCApiPtr(), index );
    }


    template< typename Iter >
    SIXTRL_INLINE void TParticles< NS(particle_real_t) >::setMass0(
        Iter begin, Iter end ) SIXTRL_NOEXCEPT
    {
        using elem_t = TParticles< NS(particle_real_t) >::num_elements_t;
        elem_t const in_num_particles = std::distance( begin, end );

        if( in_num_particles <= this->getNumParticles() )
        {
            std::copy( begin, end, this->getMass0() );
        }

        return;
    }


    SIXTRL_INLINE void TParticles< NS(particle_real_t) >::setMass0Value(
        TParticles< NS(particle_real_t) >::index_t const index,
        TParticles< NS(particle_real_t) >::real_t const value ) SIXTRL_NOEXCEPT
    {
        ::NS(Particles_set_mass0_value)( this->getCApiPtr(), index, value );
        return;
    }


    SIXTRL_INLINE void TParticles< NS(particle_real_t) >::assignMass0Ptr(
        TParticles< NS(particle_real_t) >::real_pointer_t ptr ) SIXTRL_NOEXCEPT
    {
        ::NS(Particles_assign_ptr_to_mass0)( this->getCApiPtr(), ptr );
        return;
    }

    /* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */


    SIXTRL_INLINE TParticles< NS(particle_real_t) >::const_real_pointer_t
    TParticles< NS(particle_real_t) >::getBeta0() const SIXTRL_NOEXCEPT
    {
        return ::NS(Particles_get_const_beta0)( this->getCApiPtr() );
    }


    SIXTRL_INLINE TParticles< NS(particle_real_t) >::real_pointer_t
    TParticles< NS(particle_real_t) >::getBeta0() SIXTRL_NOEXCEPT
    {
        return ::NS(Particles_get_beta0)( this->getCApiPtr() );
    }


    SIXTRL_INLINE TParticles< NS(particle_real_t) >::real_t
    TParticles< NS(particle_real_t) >::getBeta0Value(
        TParticles< NS(particle_real_t) >::index_t const index ) const SIXTRL_NOEXCEPT
    {
        return ::NS(Particles_get_beta0_value)( this->getCApiPtr(), index );
    }


    template< typename Iter >
    SIXTRL_INLINE void TParticles< NS(particle_real_t) >::setBeta0(
        Iter begin, Iter end ) SIXTRL_NOEXCEPT
    {
        using elem_t = TParticles< NS(particle_real_t) >::num_elements_t;
        elem_t const in_num_particles = std::distance( begin, end );

        if( in_num_particles <= this->getNumParticles() )
        {
            std::copy( begin, end, this->getBeta0() );
        }

        return;
    }


    SIXTRL_INLINE void TParticles< NS(particle_real_t) >::setBeta0Value(
        TParticles< NS(particle_real_t) >::index_t const index,
        TParticles< NS(particle_real_t) >::real_t const value ) SIXTRL_NOEXCEPT
    {
        ::NS(Particles_set_beta0_value)( this->getCApiPtr(), index, value );
        return;
    }


    SIXTRL_INLINE void TParticles< NS(particle_real_t) >::assignBeta0Ptr(
        TParticles< NS(particle_real_t) >::real_pointer_t ptr ) SIXTRL_NOEXCEPT
    {
        ::NS(Particles_assign_ptr_to_beta0)( this->getCApiPtr(), ptr );
        return;
    }

    /* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */


    SIXTRL_INLINE TParticles< NS(particle_real_t) >::const_real_pointer_t
    TParticles< NS(particle_real_t) >::getGamma0() const SIXTRL_NOEXCEPT
    {
        return ::NS(Particles_get_const_gamma0)( this->getCApiPtr() );
    }


    SIXTRL_INLINE TParticles< NS(particle_real_t) >::real_pointer_t
    TParticles< NS(particle_real_t) >::getGamma0() SIXTRL_NOEXCEPT
    {
        return ::NS(Particles_get_gamma0)( this->getCApiPtr() );
    }


    SIXTRL_INLINE TParticles< NS(particle_real_t) >::real_t
    TParticles< NS(particle_real_t) >::getGamma0Value(
        TParticles< NS(particle_real_t) >::index_t const index ) const SIXTRL_NOEXCEPT
    {
        return ::NS(Particles_get_gamma0_value)( this->getCApiPtr(), index );
    }


    template< typename Iter >
    SIXTRL_INLINE void TParticles< NS(particle_real_t) >::setGamma0(
        Iter begin, Iter end ) SIXTRL_NOEXCEPT
    {
        using elem_t = TParticles< NS(particle_real_t) >::num_elements_t;
        elem_t const in_num_particles = std::distance( begin, end );

        if( in_num_particles <= this->getNumParticles() )
        {
            std::copy( begin, end, this->getGamma0() );
        }

        return;
    }


    SIXTRL_INLINE void TParticles< NS(particle_real_t) >::setGamma0Value(
        TParticles< NS(particle_real_t) >::index_t const index,
        TParticles< NS(particle_real_t) >::real_t const value ) SIXTRL_NOEXCEPT
    {
        ::NS(Particles_set_gamma0_value)( this->getCApiPtr(), index, value );
        return;
    }


    SIXTRL_INLINE void TParticles< NS(particle_real_t) >::assignGamma0Ptr(
        TParticles< NS(particle_real_t) >::real_pointer_t ptr ) SIXTRL_NOEXCEPT
    {
        ::NS(Particles_assign_ptr_to_gamma0)( this->getCApiPtr(), ptr );
        return;
    }

    /* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */


    SIXTRL_INLINE TParticles< NS(particle_real_t) >::const_real_pointer_t
    TParticles< NS(particle_real_t) >::getP0c() const SIXTRL_NOEXCEPT
    {
        return ::NS(Particles_get_const_p0c)( this->getCApiPtr() );
    }


    SIXTRL_INLINE TParticles< NS(particle_real_t) >::real_pointer_t
    TParticles< NS(particle_real_t) >::getP0c() SIXTRL_NOEXCEPT
    {
        return ::NS(Particles_get_p0c)( this->getCApiPtr() );
    }


    SIXTRL_INLINE TParticles< NS(particle_real_t) >::real_t
    TParticles< NS(particle_real_t) >::getP0cValue(
        TParticles< NS(particle_real_t) >::index_t const index ) const SIXTRL_NOEXCEPT
    {
        return ::NS(Particles_get_p0c_value)( this->getCApiPtr(), index );
    }


    template< typename Iter >
    SIXTRL_INLINE void TParticles< NS(particle_real_t) >::setP0c(
        Iter begin, Iter end ) SIXTRL_NOEXCEPT
    {
        using elem_t = TParticles< NS(particle_real_t) >::num_elements_t;
        elem_t const in_num_particles = std::distance( begin, end );

        if( in_num_particles <= this->getNumParticles() )
        {
            std::copy( begin, end, this->getP0c() );
        }

        return;
    }


    SIXTRL_INLINE void TParticles< NS(particle_real_t) >::setP0cValue(
        TParticles< NS(particle_real_t) >::index_t const index,
        TParticles< NS(particle_real_t) >::real_t const value ) SIXTRL_NOEXCEPT
    {
        ::NS(Particles_set_p0c_value)( this->getCApiPtr(), index, value );
        return;
    }


    SIXTRL_INLINE void TParticles< NS(particle_real_t) >::assignP0cPtr(
        TParticles< NS(particle_real_t) >::real_pointer_t ptr ) SIXTRL_NOEXCEPT
    {
        ::NS(Particles_assign_ptr_to_p0c)( this->getCApiPtr(), ptr );
        return;
    }

    /* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */


    SIXTRL_INLINE TParticles< NS(particle_real_t) >::const_real_pointer_t
    TParticles< NS(particle_real_t) >::getS() const SIXTRL_NOEXCEPT
    {
        return ::NS(Particles_get_const_s)( this->getCApiPtr() );
    }


    SIXTRL_INLINE TParticles< NS(particle_real_t) >::real_pointer_t
    TParticles< NS(particle_real_t) >::getS() SIXTRL_NOEXCEPT
    {
        return ::NS(Particles_get_s)( this->getCApiPtr() );
    }


    SIXTRL_INLINE TParticles< NS(particle_real_t) >::real_t
    TParticles< NS(particle_real_t) >::getSValue(
        TParticles< NS(particle_real_t) >::index_t const index ) const SIXTRL_NOEXCEPT
    {
        return ::NS(Particles_get_s_value)( this->getCApiPtr(), index );
    }


    template< typename Iter >
    SIXTRL_INLINE void TParticles< NS(particle_real_t) >::setS(
        Iter begin, Iter end ) SIXTRL_NOEXCEPT
    {
        using elem_t = TParticles< NS(particle_real_t) >::num_elements_t;
        elem_t const in_num_particles = std::distance( begin, end );

        if( in_num_particles <= this->getNumParticles() )
        {
            std::copy( begin, end, this->getS() );
        }

        return;
    }


    SIXTRL_INLINE void TParticles< NS(particle_real_t) >::setSValue(
        TParticles< NS(particle_real_t) >::index_t const index,
        TParticles< NS(particle_real_t) >::real_t const value ) SIXTRL_NOEXCEPT
    {
        ::NS(Particles_set_s_value)( this->getCApiPtr(), index, value );
        return;
    }


    SIXTRL_INLINE void TParticles< NS(particle_real_t) >::assignSPtr(
        TParticles< NS(particle_real_t) >::real_pointer_t ptr ) SIXTRL_NOEXCEPT
    {
        ::NS(Particles_assign_ptr_to_s)( this->getCApiPtr(), ptr );
        return;
    }

    /* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */


    SIXTRL_INLINE TParticles< NS(particle_real_t) >::const_real_pointer_t
    TParticles< NS(particle_real_t) >::getX() const SIXTRL_NOEXCEPT
    {
        return ::NS(Particles_get_const_x)( this->getCApiPtr() );
    }


    SIXTRL_INLINE TParticles< NS(particle_real_t) >::real_pointer_t
    TParticles< NS(particle_real_t) >::getX() SIXTRL_NOEXCEPT
    {
        return ::NS(Particles_get_x)( this->getCApiPtr() );
    }


    SIXTRL_INLINE TParticles< NS(particle_real_t) >::real_t
    TParticles< NS(particle_real_t) >::getXValue(
        TParticles< NS(particle_real_t) >::index_t const index ) const SIXTRL_NOEXCEPT
    {
        return ::NS(Particles_get_x_value)( this->getCApiPtr(), index );
    }


    template< typename Iter >
    SIXTRL_INLINE void TParticles< NS(particle_real_t) >::setX(
        Iter begin, Iter end ) SIXTRL_NOEXCEPT
    {
        using elem_t = TParticles< NS(particle_real_t) >::num_elements_t;
        elem_t const in_num_particles = std::distance( begin, end );

        if( in_num_particles <= this->getNumParticles() )
        {
            std::copy( begin, end, this->getX() );
        }

        return;
    }


    SIXTRL_INLINE void TParticles< NS(particle_real_t) >::setXValue(
        TParticles< NS(particle_real_t) >::index_t const index,
        TParticles< NS(particle_real_t) >::real_t const value ) SIXTRL_NOEXCEPT
    {
        ::NS(Particles_set_x_value)( this->getCApiPtr(), index, value );
        return;
    }


    SIXTRL_INLINE void TParticles< NS(particle_real_t) >::assignXPtr(
        TParticles< NS(particle_real_t) >::real_pointer_t ptr ) SIXTRL_NOEXCEPT
    {
        ::NS(Particles_assign_ptr_to_x)( this->getCApiPtr(), ptr );
        return;
    }

    /* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */


    SIXTRL_INLINE TParticles< NS(particle_real_t) >::const_real_pointer_t
    TParticles< NS(particle_real_t) >::getY() const SIXTRL_NOEXCEPT
    {
        return ::NS(Particles_get_const_y)( this->getCApiPtr() );
    }


    SIXTRL_INLINE TParticles< NS(particle_real_t) >::real_pointer_t
    TParticles< NS(particle_real_t) >::getY() SIXTRL_NOEXCEPT
    {
        return ::NS(Particles_get_y)( this->getCApiPtr() );
    }


    SIXTRL_INLINE TParticles< NS(particle_real_t) >::real_t
    TParticles< NS(particle_real_t) >::getYValue(
        TParticles< NS(particle_real_t) >::index_t const index ) const SIXTRL_NOEXCEPT
    {
        return ::NS(Particles_get_y_value)( this->getCApiPtr(), index );
    }


    template< typename Iter >
    SIXTRL_INLINE void TParticles< NS(particle_real_t) >::setY(
        Iter begin, Iter end ) SIXTRL_NOEXCEPT
    {
        using elem_t = TParticles< NS(particle_real_t) >::num_elements_t;
        elem_t const in_num_particles = std::distance( begin, end );

        if( in_num_particles <= this->getNumParticles() )
        {
            std::copy( begin, end, this->getQ0() );
        }

        return;
    }


    SIXTRL_INLINE void TParticles< NS(particle_real_t) >::setYValue(
        TParticles< NS(particle_real_t) >::index_t const index,
        TParticles< NS(particle_real_t) >::real_t const value ) SIXTRL_NOEXCEPT
    {
        ::NS(Particles_set_y_value)( this->getCApiPtr(), index, value );
        return;
    }


    SIXTRL_INLINE void TParticles< NS(particle_real_t) >::assignYPtr(
        TParticles< NS(particle_real_t) >::real_pointer_t ptr ) SIXTRL_NOEXCEPT
    {
        ::NS(Particles_assign_ptr_to_y)( this->getCApiPtr(), ptr );
        return;
    }

    /* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */


    SIXTRL_INLINE TParticles< NS(particle_real_t) >::const_real_pointer_t
    TParticles< NS(particle_real_t) >::getPx() const SIXTRL_NOEXCEPT
    {
        return ::NS(Particles_get_const_px)( this->getCApiPtr() );
    }


    SIXTRL_INLINE TParticles< NS(particle_real_t) >::real_pointer_t
    TParticles< NS(particle_real_t) >::getPx() SIXTRL_NOEXCEPT
    {
        return ::NS(Particles_get_px)( this->getCApiPtr() );
    }


    SIXTRL_INLINE TParticles< NS(particle_real_t) >::real_t
    TParticles< NS(particle_real_t) >::getPxValue(
        TParticles< NS(particle_real_t) >::index_t const index ) const SIXTRL_NOEXCEPT
    {
        return ::NS(Particles_get_px_value)( this->getCApiPtr(), index );
    }


    template< typename Iter >
    SIXTRL_INLINE void TParticles< NS(particle_real_t) >::setPx(
        Iter begin, Iter end ) SIXTRL_NOEXCEPT
    {
        using elem_t = TParticles< NS(particle_real_t) >::num_elements_t;
        elem_t const in_num_particles = std::distance( begin, end );

        if( in_num_particles <= this->getNumParticles() )
        {
            std::copy( begin, end, this->getPx() );
        }

        return;
    }


    SIXTRL_INLINE void TParticles< NS(particle_real_t) >::setPxValue(
        TParticles< NS(particle_real_t) >::index_t const index,
        TParticles< NS(particle_real_t) >::real_t const value ) SIXTRL_NOEXCEPT
    {
        ::NS(Particles_set_px_value)( this->getCApiPtr(), index, value );
        return;
    }


    SIXTRL_INLINE void TParticles< NS(particle_real_t) >::assignPxPtr(
        TParticles< NS(particle_real_t) >::real_pointer_t ptr ) SIXTRL_NOEXCEPT
    {
        ::NS(Particles_assign_ptr_to_px)( this->getCApiPtr(), ptr );
        return;
    }

    /* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */


    SIXTRL_INLINE TParticles< NS(particle_real_t) >::const_real_pointer_t
    TParticles< NS(particle_real_t) >::getPy() const SIXTRL_NOEXCEPT
    {
        return ::NS(Particles_get_const_py)( this->getCApiPtr() );
    }


    SIXTRL_INLINE TParticles< NS(particle_real_t) >::real_pointer_t
    TParticles< NS(particle_real_t) >::getPy() SIXTRL_NOEXCEPT
    {
        return ::NS(Particles_get_py)( this->getCApiPtr() );
    }


    SIXTRL_INLINE TParticles< NS(particle_real_t) >::real_t
    TParticles< NS(particle_real_t) >::getPyValue(
        TParticles< NS(particle_real_t) >::index_t const index ) const SIXTRL_NOEXCEPT
    {
        return ::NS(Particles_get_py_value)( this->getCApiPtr(), index );
    }


    template< typename Iter >
    SIXTRL_INLINE void TParticles< NS(particle_real_t) >::setPy(
        Iter begin, Iter end ) SIXTRL_NOEXCEPT
    {
        using elem_t = TParticles< NS(particle_real_t) >::num_elements_t;
        elem_t const in_num_particles = std::distance( begin, end );

        if( in_num_particles <= this->getNumParticles() )
        {
            std::copy( begin, end, this->getPy() );
        }

        return;
    }


    SIXTRL_INLINE void TParticles< NS(particle_real_t) >::setPyValue(
        TParticles< NS(particle_real_t) >::index_t const index,
        TParticles< NS(particle_real_t) >::real_t const value ) SIXTRL_NOEXCEPT
    {
        ::NS(Particles_set_py_value)( this->getCApiPtr(), index, value );
        return;
    }


    SIXTRL_INLINE void TParticles< NS(particle_real_t) >::assignPyPtr(
        TParticles< NS(particle_real_t) >::real_pointer_t ptr ) SIXTRL_NOEXCEPT
    {
        ::NS(Particles_assign_ptr_to_py)( this->getCApiPtr(), ptr );
        return;
    }

    /* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */


    SIXTRL_INLINE TParticles< NS(particle_real_t) >::const_real_pointer_t
    TParticles< NS(particle_real_t) >::getZeta() const SIXTRL_NOEXCEPT
    {
        return ::NS(Particles_get_const_zeta)( this->getCApiPtr() );
    }


    SIXTRL_INLINE TParticles< NS(particle_real_t) >::real_pointer_t
    TParticles< NS(particle_real_t) >::getZeta() SIXTRL_NOEXCEPT
    {
        return ::NS(Particles_get_zeta)( this->getCApiPtr() );
    }


    SIXTRL_INLINE TParticles< NS(particle_real_t) >::real_t
    TParticles< NS(particle_real_t) >::getZetaValue(
        TParticles< NS(particle_real_t) >::index_t const index ) const SIXTRL_NOEXCEPT
    {
        return ::NS(Particles_get_zeta_value)( this->getCApiPtr(), index );
    }


    template< typename Iter >
    SIXTRL_INLINE void TParticles< NS(particle_real_t) >::setZeta(
        Iter begin, Iter end ) SIXTRL_NOEXCEPT
    {
        using elem_t = TParticles< NS(particle_real_t) >::num_elements_t;
        elem_t const in_num_particles = std::distance( begin, end );

        if( in_num_particles <= this->getNumParticles() )
        {
            std::copy( begin, end, this->getZeta() );
        }

        return;
    }


    SIXTRL_INLINE void TParticles< NS(particle_real_t) >::setZetaValue(
        TParticles< NS(particle_real_t) >::index_t const index,
        TParticles< NS(particle_real_t) >::real_t const value ) SIXTRL_NOEXCEPT
    {
        ::NS(Particles_set_zeta_value)( this->getCApiPtr(), index, value );
        return;
    }


    SIXTRL_INLINE void TParticles< NS(particle_real_t) >::assignZetaPtr(
        TParticles< NS(particle_real_t) >::real_pointer_t ptr ) SIXTRL_NOEXCEPT
    {
        ::NS(Particles_assign_ptr_to_zeta)( this->getCApiPtr(), ptr );
        return;
    }

    /* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */


    SIXTRL_INLINE TParticles< NS(particle_real_t) >::const_real_pointer_t
    TParticles< NS(particle_real_t) >::getPSigma() const SIXTRL_NOEXCEPT
    {
        return ::NS(Particles_get_const_psigma)( this->getCApiPtr() );
    }


    SIXTRL_INLINE TParticles< NS(particle_real_t) >::real_pointer_t
    TParticles< NS(particle_real_t) >::getPSigma() SIXTRL_NOEXCEPT
    {
        return ::NS(Particles_get_psigma)( this->getCApiPtr() );
    }


    SIXTRL_INLINE TParticles< NS(particle_real_t) >::real_t
    TParticles< NS(particle_real_t) >::getPSigmaValue(
        TParticles< NS(particle_real_t) >::index_t const index ) const SIXTRL_NOEXCEPT
    {
        return ::NS(Particles_get_psigma_value)( this->getCApiPtr(), index );
    }


    template< typename Iter >
    SIXTRL_INLINE void TParticles< NS(particle_real_t) >::setPSigma(
        Iter begin, Iter end ) SIXTRL_NOEXCEPT
    {
        using elem_t = TParticles< NS(particle_real_t) >::num_elements_t;
        elem_t const in_num_particles = std::distance( begin, end );

        if( in_num_particles <= this->getNumParticles() )
        {
            std::copy( begin, end, this->getPSigma() );
        }

        return;
    }


    SIXTRL_INLINE void TParticles< NS(particle_real_t) >::setPSigmaValue(
        TParticles< NS(particle_real_t) >::index_t const index,
        TParticles< NS(particle_real_t) >::real_t const value ) SIXTRL_NOEXCEPT
    {
        ::NS(Particles_set_psigma_value)( this->getCApiPtr(), index, value );
        return;
    }


    SIXTRL_INLINE void TParticles< NS(particle_real_t) >::assignPSigmaPtr(
        TParticles< NS(particle_real_t) >::real_pointer_t ptr ) SIXTRL_NOEXCEPT
    {
        ::NS(Particles_assign_ptr_to_psigma)( this->getCApiPtr(), ptr );
        return;
    }

    /* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */


    SIXTRL_INLINE TParticles< NS(particle_real_t) >::const_real_pointer_t
    TParticles< NS(particle_real_t) >::getDelta() const SIXTRL_NOEXCEPT
    {
        return ::NS(Particles_get_const_delta)( this->getCApiPtr() );
    }


    SIXTRL_INLINE TParticles< NS(particle_real_t) >::real_pointer_t
    TParticles< NS(particle_real_t) >::getDelta() SIXTRL_NOEXCEPT
    {
        return ::NS(Particles_get_delta)( this->getCApiPtr() );
    }


    SIXTRL_INLINE TParticles< NS(particle_real_t) >::real_t
    TParticles< NS(particle_real_t) >::getDeltaValue(
        TParticles< NS(particle_real_t) >::index_t const index ) const SIXTRL_NOEXCEPT
    {
        return ::NS(Particles_get_delta_value)( this->getCApiPtr(), index );
    }


    template< typename Iter >
    SIXTRL_INLINE void TParticles< NS(particle_real_t) >::setDelta(
        Iter begin, Iter end ) SIXTRL_NOEXCEPT
    {
        using elem_t = TParticles< NS(particle_real_t) >::num_elements_t;
        elem_t const in_num_particles = std::distance( begin, end );

        if( in_num_particles <= this->getNumParticles() )
        {
            std::copy( begin, end, this->getDelta() );
        }

        return;
    }


    SIXTRL_INLINE void TParticles< NS(particle_real_t) >::setDeltaValue(
        TParticles< NS(particle_real_t) >::index_t const index,
        TParticles< NS(particle_real_t) >::real_t const value ) SIXTRL_NOEXCEPT
    {
        ::NS(Particles_set_delta_value)( this->getCApiPtr(), index, value );
        return;
    }


    SIXTRL_INLINE void TParticles< NS(particle_real_t) >::assignDeltaPtr(
        TParticles< NS(particle_real_t) >::real_pointer_t ptr ) SIXTRL_NOEXCEPT
    {
        ::NS(Particles_assign_ptr_to_delta)( this->getCApiPtr(), ptr );
        return;
    }

    /* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */


    SIXTRL_INLINE TParticles< NS(particle_real_t) >::const_real_pointer_t
    TParticles< NS(particle_real_t) >::getRpp() const SIXTRL_NOEXCEPT
    {
        return ::NS(Particles_get_const_rpp)( this->getCApiPtr() );
    }


    SIXTRL_INLINE TParticles< NS(particle_real_t) >::real_pointer_t
    TParticles< NS(particle_real_t) >::getRpp() SIXTRL_NOEXCEPT
    {
        return ::NS(Particles_get_rpp)( this->getCApiPtr() );
    }


    SIXTRL_INLINE TParticles< NS(particle_real_t) >::real_t
    TParticles< NS(particle_real_t) >::getRppValue(
        TParticles< NS(particle_real_t) >::index_t const index ) const SIXTRL_NOEXCEPT
    {
        return ::NS(Particles_get_rpp_value)( this->getCApiPtr(), index );
    }


    template< typename Iter >
    SIXTRL_INLINE void TParticles< NS(particle_real_t) >::setRpp(
        Iter begin, Iter end ) SIXTRL_NOEXCEPT
    {
        using elem_t = TParticles< NS(particle_real_t) >::num_elements_t;
        elem_t const in_num_particles = std::distance( begin, end );

        if( in_num_particles <= this->getNumParticles() )
        {
            std::copy( begin, end, this->getRpp() );
        }

        return;
    }


    SIXTRL_INLINE void TParticles< NS(particle_real_t) >::setRppValue(
        TParticles< NS(particle_real_t) >::index_t const index,
        TParticles< NS(particle_real_t) >::real_t const value ) SIXTRL_NOEXCEPT
    {
        ::NS(Particles_set_rpp_value)( this->getCApiPtr(), index, value );
        return;
    }


    SIXTRL_INLINE void TParticles< NS(particle_real_t) >::assignRppPtr(
        TParticles< NS(particle_real_t) >::real_pointer_t ptr ) SIXTRL_NOEXCEPT
    {
        ::NS(Particles_assign_ptr_to_rpp)( this->getCApiPtr(), ptr );
        return;
    }

    /* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */


    SIXTRL_INLINE TParticles< NS(particle_real_t) >::const_real_pointer_t
    TParticles< NS(particle_real_t) >::getRvv() const SIXTRL_NOEXCEPT
    {
        return ::NS(Particles_get_const_rvv)( this->getCApiPtr() );
    }


    SIXTRL_INLINE TParticles< NS(particle_real_t) >::real_pointer_t
    TParticles< NS(particle_real_t) >::getRvv() SIXTRL_NOEXCEPT
    {
        return ::NS(Particles_get_rvv)( this->getCApiPtr() );
    }


    SIXTRL_INLINE TParticles< NS(particle_real_t) >::real_t
    TParticles< NS(particle_real_t) >::getRvvValue(
        TParticles< NS(particle_real_t) >::index_t const index ) const SIXTRL_NOEXCEPT
    {
        return ::NS(Particles_get_rvv_value)( this->getCApiPtr(), index );
    }


    template< typename Iter >
    SIXTRL_INLINE void TParticles< NS(particle_real_t) >::setRvv(
        Iter begin, Iter end ) SIXTRL_NOEXCEPT
    {
        using elem_t = TParticles< NS(particle_real_t) >::num_elements_t;
        elem_t const in_num_particles = std::distance( begin, end );

        if( in_num_particles <= this->getNumParticles() )
        {
            std::copy( begin, end, this->getRvv() );
        }

        return;
    }


    SIXTRL_INLINE void TParticles< NS(particle_real_t) >::setRvvValue(
        TParticles< NS(particle_real_t) >::index_t const index,
        TParticles< NS(particle_real_t) >::real_t const value ) SIXTRL_NOEXCEPT
    {
        ::NS(Particles_set_rvv_value)( this->getCApiPtr(), index, value );
        return;
    }


    SIXTRL_INLINE void TParticles< NS(particle_real_t) >::assignRvvPtr(
        TParticles< NS(particle_real_t) >::real_pointer_t ptr ) SIXTRL_NOEXCEPT
    {
        ::NS(Particles_assign_ptr_to_rvv)( this->getCApiPtr(), ptr );
        return;
    }

    /* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */


    SIXTRL_INLINE TParticles< NS(particle_real_t) >::const_real_pointer_t
    TParticles< NS(particle_real_t) >::getChi() const SIXTRL_NOEXCEPT
    {
        return ::NS(Particles_get_const_chi)( this->getCApiPtr() );
    }


    SIXTRL_INLINE TParticles< NS(particle_real_t) >::real_pointer_t
    TParticles< NS(particle_real_t) >::getChi() SIXTRL_NOEXCEPT
    {
        return ::NS(Particles_get_chi)( this->getCApiPtr() );
    }


    SIXTRL_INLINE TParticles< NS(particle_real_t) >::real_t
    TParticles< NS(particle_real_t) >::getChiValue(
        TParticles< NS(particle_real_t) >::index_t const index ) const SIXTRL_NOEXCEPT
    {
        return ::NS(Particles_get_chi_value)( this->getCApiPtr(), index );
    }


    template< typename Iter >
    SIXTRL_INLINE void TParticles< NS(particle_real_t) >::setChi(
        Iter begin, Iter end ) SIXTRL_NOEXCEPT
    {
        using elem_t = TParticles< NS(particle_real_t) >::num_elements_t;
        elem_t const in_num_particles = std::distance( begin, end );

        if( in_num_particles <= this->getNumParticles() )
        {
            std::copy( begin, end, this->getChi() );
        }

        return;
    }


    SIXTRL_INLINE void TParticles< NS(particle_real_t) >::setChiValue(
        TParticles< NS(particle_real_t) >::index_t const index,
        TParticles< NS(particle_real_t) >::real_t const value ) SIXTRL_NOEXCEPT
    {
        ::NS(Particles_set_chi_value)( this->getCApiPtr(), index, value );
        return;
    }


    SIXTRL_INLINE void TParticles< NS(particle_real_t) >::assignChiPtr(
        TParticles< NS(particle_real_t) >::real_pointer_t ptr ) SIXTRL_NOEXCEPT
    {
        ::NS(Particles_assign_ptr_to_chi)( this->getCApiPtr(), ptr );
        return;
    }

    /* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */


    SIXTRL_INLINE TParticles< NS(particle_real_t) >::const_index_pointer_t
    TParticles< NS(particle_real_t) >::getParticleId() const SIXTRL_NOEXCEPT
    {
        return ::NS(Particles_get_const_particle_id)( this->getCApiPtr() );
    }


    SIXTRL_INLINE TParticles< NS(particle_real_t) >::index_pointer_t
    TParticles< NS(particle_real_t) >::getParticleId() SIXTRL_NOEXCEPT
    {
        return ::NS(Particles_get_particle_id)( this->getCApiPtr() );
    }


    SIXTRL_INLINE TParticles< NS(particle_real_t) >::index_t
    TParticles< NS(particle_real_t) >::getParticleIdValue(
        TParticles< NS(particle_real_t) >::index_t
            const index ) const SIXTRL_NOEXCEPT
    {
        return ::NS(Particles_get_particle_id_value)(
            this->getCApiPtr(), index );
    }


    template< typename Iter >
    SIXTRL_INLINE void TParticles< NS(particle_real_t) >::setParticleId(
        Iter begin, Iter end ) SIXTRL_NOEXCEPT
    {
        using elem_t = TParticles< NS(particle_real_t) >::num_elements_t;
        elem_t const in_num_particles = std::distance( begin, end );

        if( in_num_particles <= this->getNumParticles() )
        {
            std::copy( begin, end, this->getParticleId() );
        }

        return;
    }


    SIXTRL_INLINE void TParticles< NS(particle_real_t) >::setParticleIdValue(
        TParticles< NS(particle_real_t) >::index_t const index,
        TParticles< NS(particle_real_t) >::index_t const value ) SIXTRL_NOEXCEPT
    {
        ::NS(Particles_set_particle_id_value)(
            this->getCApiPtr(), index, value );

        return;
    }


    SIXTRL_INLINE void TParticles< NS(particle_real_t) >::assignParticleIdPtr(
        TParticles< NS(particle_real_t) >::index_pointer_t ptr ) SIXTRL_NOEXCEPT
    {
        ::NS(Particles_assign_ptr_to_particle_id)( this->getCApiPtr(), ptr );
        return;
    }

    /* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */


    SIXTRL_INLINE TParticles< NS(particle_real_t) >::const_index_pointer_t
    TParticles< NS(particle_real_t) >::getAtElementId() const SIXTRL_NOEXCEPT
    {
        return ::NS(Particles_get_const_at_element_id)( this->getCApiPtr() );
    }


    SIXTRL_INLINE TParticles< NS(particle_real_t) >::index_pointer_t
    TParticles< NS(particle_real_t) >::getAtElementId() SIXTRL_NOEXCEPT
    {
        return ::NS(Particles_get_at_element_id)( this->getCApiPtr() );
    }


    SIXTRL_INLINE TParticles< NS(particle_real_t) >::index_t
    TParticles< NS(particle_real_t) >::getAtElementIdValue(
        TParticles< NS(particle_real_t) >::index_t
            const index ) const SIXTRL_NOEXCEPT
    {
        return ::NS(Particles_get_at_element_id_value)(
            this->getCApiPtr(), index );
    }


    template< typename Iter >
    SIXTRL_INLINE void TParticles< NS(particle_real_t) >::setAtElementId(
        Iter begin, Iter end ) SIXTRL_NOEXCEPT
    {
        using elem_t = TParticles< NS(particle_real_t) >::num_elements_t;
        elem_t const in_num_particles = std::distance( begin, end );

        if( in_num_particles <= this->getNumParticles() )
        {
            std::copy( begin, end, this->getAtElementId() );
        }

        return;
    }


    SIXTRL_INLINE void TParticles< NS(particle_real_t) >::setAtElementIdValue(
        TParticles< NS(particle_real_t) >::index_t const index,
        TParticles< NS(particle_real_t) >::index_t const value ) SIXTRL_NOEXCEPT
    {
        ::NS(Particles_set_at_element_id_value)(
            this->getCApiPtr(), index, value );

        return;
    }


    SIXTRL_INLINE void TParticles< NS(particle_real_t) >::assignAtElementIdPtr(
        TParticles< NS(particle_real_t) >::index_pointer_t ptr ) SIXTRL_NOEXCEPT
    {
        ::NS(Particles_assign_ptr_to_at_element_id)( this->getCApiPtr(), ptr );
        return;
    }

    /* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */


    SIXTRL_INLINE TParticles< NS(particle_real_t) >::const_index_pointer_t
    TParticles< NS(particle_real_t) >::getAtTurn() const SIXTRL_NOEXCEPT
    {
        return ::NS(Particles_get_const_at_turn)( this->getCApiPtr() );
    }


    SIXTRL_INLINE TParticles< NS(particle_real_t) >::index_pointer_t
    TParticles< NS(particle_real_t) >::getAtTurn() SIXTRL_NOEXCEPT
    {
        return ::NS(Particles_get_at_turn)( this->getCApiPtr() );
    }


    SIXTRL_INLINE TParticles< NS(particle_real_t) >::index_t
    TParticles< NS(particle_real_t) >::getAtTurnValue(
        TParticles< NS(particle_real_t) >::index_t
            const index ) const SIXTRL_NOEXCEPT
    {
        return ::NS(Particles_get_at_turn_value)(
            this->getCApiPtr(), index );
    }


    template< typename Iter >
    SIXTRL_INLINE void TParticles< NS(particle_real_t) >::setAtTurn(
        Iter begin, Iter end ) SIXTRL_NOEXCEPT
    {
        using elem_t = TParticles< NS(particle_real_t) >::num_elements_t;
        elem_t const in_num_particles = std::distance( begin, end );

        if( in_num_particles <= this->getNumParticles() )
        {
            std::copy( begin, end, this->getAtTurn() );
        }

        return;
    }


    SIXTRL_INLINE void TParticles< NS(particle_real_t) >::setAtTurnValue(
        TParticles< NS(particle_real_t) >::index_t const index,
        TParticles< NS(particle_real_t) >::index_t const value ) SIXTRL_NOEXCEPT
    {
        ::NS(Particles_set_at_turn_value)(
            this->getCApiPtr(), index, value );

        return;
    }


    SIXTRL_INLINE void TParticles< NS(particle_real_t) >::assignAtTurnPtr(
        TParticles< NS(particle_real_t) >::index_pointer_t ptr ) SIXTRL_NOEXCEPT
    {
        ::NS(Particles_assign_ptr_to_at_turn)( this->getCApiPtr(), ptr );
        return;
    }

    /* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */


    SIXTRL_INLINE TParticles< NS(particle_real_t) >::const_index_pointer_t
    TParticles< NS(particle_real_t) >::getState() const SIXTRL_NOEXCEPT
    {
        return ::NS(Particles_get_const_state)( this->getCApiPtr() );
    }


    SIXTRL_INLINE TParticles< NS(particle_real_t) >::index_pointer_t
    TParticles< NS(particle_real_t) >::getState() SIXTRL_NOEXCEPT
    {
        return ::NS(Particles_get_state)( this->getCApiPtr() );
    }


    SIXTRL_INLINE TParticles< NS(particle_real_t) >::index_t
    TParticles< NS(particle_real_t) >::getStateValue(
        TParticles< NS(particle_real_t) >::index_t
            const index ) const SIXTRL_NOEXCEPT
    {
        return ::NS(Particles_get_state_value)(
            this->getCApiPtr(), index );
    }


    template< typename Iter >
    SIXTRL_INLINE void TParticles< NS(particle_real_t) >::setState(
        Iter begin, Iter end ) SIXTRL_NOEXCEPT
    {
        using elem_t = TParticles< NS(particle_real_t) >::num_elements_t;
        elem_t const in_num_particles = std::distance( begin, end );

        if( in_num_particles <= this->getNumParticles() )
        {
            std::copy( begin, end, this->getState() );
        }

        return;
    }


    SIXTRL_INLINE void TParticles< NS(particle_real_t) >::setStateValue(
        TParticles< NS(particle_real_t) >::index_t const index,
        TParticles< NS(particle_real_t) >::index_t const value ) SIXTRL_NOEXCEPT
    {
        ::NS(Particles_set_state_value)(
            this->getCApiPtr(), index, value );

        return;
    }


    SIXTRL_INLINE void TParticles< NS(particle_real_t) >::assignStatePtr(
        TParticles< NS(particle_real_t) >::index_pointer_t ptr ) SIXTRL_NOEXCEPT
    {
        ::NS(Particles_assign_ptr_to_state)( this->getCApiPtr(), ptr );
        return;
    }

    SIXTRL_INLINE bool Buffer_is_particles_buffer(
        Buffer const& SIXTRL_RESTRICT_REF buffer )
    {
        return NS(Buffer_is_particles_buffer)( buffer.getCApiPtr() );
    }

    SIXTRL_INLINE Particles::size_type
    Particles_buffer_get_total_num_of_particles(
        Buffer const& SIXTRL_RESTRICT_REF buffer )
    {
        return NS(Particles_buffer_get_total_num_of_particles)(
            buffer.getCApiPtr() );
    }

    SIXTRL_INLINE Buffer::size_type Particles_buffer_get_num_of_particle_blocks(
        Buffer const& SIXTRL_RESTRICT_REF buffer )
    {
        return NS(Particles_buffer_get_num_of_particle_blocks)(
            buffer.getCApiPtr() );
    }
}

#endif /* defined( __cplusplus ) */

#endif /* CXX_SIXTRACKLIB_COMMON_PARTICLES_HPP__ */

/* end: /home/martin/git/sixtracklib/sixtracklib/common/particles.hpp */